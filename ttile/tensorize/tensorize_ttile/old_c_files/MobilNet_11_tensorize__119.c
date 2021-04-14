
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 8)); ((Iter 4), (Arg 14))]; T (32, c);
  T (28, x)]
*/
IND_TYPE c, cp_0, c414_p_0, cp_1, c414, h, hp_0, w, wp_0, x, xp_0, x552_p_0, x553_p_0, xp_1, x552_p_1, xp_2, x552, x553, y, yp_0;
IND_TYPE y276 = 0;
IND_TYPE x554 = 0;
IND_TYPE h256 = 0;
IND_TYPE w276 = 0;
IND_TYPE c415 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4256 ,mem_vec_4257 ,mem_vec_4258 ,mem_vec_4259 ,mem_vec_4260 ,mem_vec_4261 ,mem_vec_4262 ,mem_vec_4263 ,mem_vec_4264 ,mem_vec_4265 ,mem_vec_4266 ,mem_vec_4267 ,mem_vec_4268 ,mem_vec_4269 ,mem_vec_4270 ,mem_vec_4271 ,mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,mem_vec_4280 ,mem_vec_4281 ,mem_vec_4282 ,mem_vec_4283 ,mem_vec_4284 ,mem_vec_4285 ,mem_vec_4286 ,mem_vec_4287 ,mem_vec_4288 ,mem_vec_4289 ,mem_vec_4290 ,mem_vec_4291 ,mem_vec_4292 ,mem_vec_4293 ,mem_vec_4294 ,mem_vec_4295 ,mem_vec_4296 ,mem_vec_4297 ,mem_vec_4298 ,mem_vec_4299 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 28) (112 / 4)
x553 = 0;
x553_p_0 = 0;
c414 = 0;
c414_p_0 = 0;
y = 0;
yp_0 = 0;
x552 = 0;
x552_p_1 = 0;
					for (h = h256, hp_0 = 0;h < h256 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w276, wp_0 = 0;w < w276 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
							// T (x, 1) (1 / 1)
							for (x = x552, xp_2 = x552_p_1, xp_1 = x552_p_0, xp_0 = 0;x < x552 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4256 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4257 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4258 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4259 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4260 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4261 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4262 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4263 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4264 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4265 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4266 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4267 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4268 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4269 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4270 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4271 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c414, cp_1 = c414_p_0, cp_0 = 0;c < c414 + 1;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4256);
											mem_vec_4256 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4257);
											mem_vec_4257 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4258);
											mem_vec_4258 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4259);
											mem_vec_4259 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4260);
											mem_vec_4260 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4261);
											mem_vec_4261 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4262);
											mem_vec_4262 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4263);
											mem_vec_4263 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4264);
											mem_vec_4264 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4265);
											mem_vec_4265 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4266);
											mem_vec_4266 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4267);
											mem_vec_4267 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4268);
											mem_vec_4268 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4269);
											mem_vec_4269 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4270);
											mem_vec_4270 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4271);
											mem_vec_4271 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4256);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4257);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4258);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4259);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4260);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4261);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4262);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4263);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4264);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4265);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4266);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4267);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4268);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4269);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4270);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4271);
							}
						}
					}
}
