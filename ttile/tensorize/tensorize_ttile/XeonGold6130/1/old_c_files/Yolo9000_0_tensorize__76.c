
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h); T (4, y); T (8, x); T (68, x); T (17, y)]
*/
IND_TYPE c, cp_0, c390_p_0, cp_1, c390, h, hp_0, w, wp_0, x, xp_0, x568_p_0, x569_p_0, xp_1, x568_p_1, xp_2, x568, x569, y, yp_0, y462_p_0, yp_1, y462;
IND_TYPE y463 = 0;
IND_TYPE x570 = 0;
IND_TYPE h248 = 0;
IND_TYPE w284 = 0;
IND_TYPE c391 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_4224 ,mem_vec_4225 ,mem_vec_4226 ,mem_vec_4227 ,mem_vec_4228 ,mem_vec_4229 ,mem_vec_4230 ,mem_vec_4231 ,mem_vec_4232 ,mem_vec_4233 ,mem_vec_4234 ,mem_vec_4235 ,mem_vec_4236 ,mem_vec_4237 ,mem_vec_4238 ,mem_vec_4239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 17) (544 / 32)
y462 = 0;
y462_p_0 = 0;
x569 = 0;
x569_p_0 = 0;
x568 = 0;
x568_p_1 = 0;
y = 0;
yp_1 = 0;
				for (h = h248, hp_0 = 0;h < h248 + 3;h += 1, hp_0 += 1){
					// y = 8, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w284, wp_0 = 0;w < w284 + 3;w += 1, wp_0 += 1){
						// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c390 = c391, c390_p_0 = 0;c390 < c391 + 3;c390 += 3, c390_p_0 += 3){
							// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x568, xp_2 = x568_p_1, xp_1 = x568_p_0, xp_0 = 0;x < x568 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4224 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4225 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4226 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4227 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4228 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4229 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4230 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4231 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4232 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4233 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4234 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4235 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4236 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4237 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4238 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4239 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c390, cp_1 = c390_p_0, cp_0 = 0;c < c390 + 3;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4224);
											mem_vec_4224 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4225);
											mem_vec_4225 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4226);
											mem_vec_4226 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4227);
											mem_vec_4227 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4228);
											mem_vec_4228 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4229);
											mem_vec_4229 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4230);
											mem_vec_4230 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4231);
											mem_vec_4231 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4232);
											mem_vec_4232 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4233);
											mem_vec_4233 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4234);
											mem_vec_4234 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4235);
											mem_vec_4235 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4236);
											mem_vec_4236 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4237);
											mem_vec_4237 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4238);
											mem_vec_4238 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4239);
											mem_vec_4239 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4224);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4225);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4226);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4227);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4228);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4229);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4230);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4231);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4232);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4233);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4234);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4235);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4236);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4237);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4238);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4239);
							}
						}
					}
				}
}
