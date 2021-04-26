
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (17, x); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]]
*/
IND_TYPE c, cp_0, c210_p_0, cp_1, c210, f, fp_0, x, xp_0, x280_p_0, x281_p_0, xp_1, x280_p_1, xp_2, x280, x281, y, yp_0, y202_p_0, yp_1, y202;
IND_TYPE y203 = 0;
IND_TYPE x282 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c211 = 0;
IND_TYPE f140 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3196 ,mem_vec_3197 ,mem_vec_3198 ,mem_vec_3199 ,mem_vec_3200 ,mem_vec_3201 ,mem_vec_3202 ,mem_vec_3203 ,mem_vec_3204 ,mem_vec_3205 ,mem_vec_3206 ,mem_vec_3207 ,mem_vec_3208 ,mem_vec_3209 ,mem_vec_3210 ,mem_vec_3211 ,mem_vec_3212 ,mem_vec_3213 ,mem_vec_3214 ,mem_vec_3215 ,mem_vec_3216 ,mem_vec_3217 ,mem_vec_3218 ,mem_vec_3219 ,mem_vec_3220 ,mem_vec_3221 ,mem_vec_3222 ,mem_vec_3223 ,mem_vec_3224 ,mem_vec_3225 ,mem_vec_3226 ,mem_vec_3227 ,mem_vec_3228 ,mem_vec_3229 ,mem_vec_3230 ,mem_vec_3231 ,mem_vec_3232 ,mem_vec_3233 ,mem_vec_3234 ,mem_vec_3235 ,mem_vec_3236 ,mem_vec_3237 ,mem_vec_3238 ,mem_vec_3239 ,mem_vec_3240 ,mem_vec_3241 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y202 = 0;
y202_p_0 = 0;
x281 = 0;
x281_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
x280 = 0;
x280_p_1 = 0;
c210 = 0;
c210_p_0 = 0;
							for (x = x280, xp_2 = x280_p_1, xp_1 = x280_p_0, xp_0 = 0;x < x280 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3196 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_3197 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_3198 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_3199 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_3200 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_3201 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_3202 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_3203 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_3204 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_3205 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_3206 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_3207 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_3208 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_3209 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_3210 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_3211 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_3212 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_3213 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_3214 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_3215 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_3216 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_3217 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c210, cp_1 = c210_p_0, cp_0 = 0;c < c210 + 128;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3196);
											mem_vec_3196 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3197);
											mem_vec_3197 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3198);
											mem_vec_3198 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3199);
											mem_vec_3199 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3200);
											mem_vec_3200 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3201);
											mem_vec_3201 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3202);
											mem_vec_3202 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3203);
											mem_vec_3203 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3204);
											mem_vec_3204 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3205);
											mem_vec_3205 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3206);
											mem_vec_3206 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3207);
											mem_vec_3207 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3208);
											mem_vec_3208 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3209);
											mem_vec_3209 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3210);
											mem_vec_3210 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3211);
											mem_vec_3211 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3212);
											mem_vec_3212 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3213);
											mem_vec_3213 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3214);
											mem_vec_3214 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3215);
											mem_vec_3215 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3216);
											mem_vec_3216 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3217);
											mem_vec_3217 = vec_34;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3196);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3197);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3198);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3199);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3200);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3201);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3202);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3203);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3204);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3205);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3206);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3207);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3208);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3209);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3210);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3211);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3212);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3213);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3214);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3215);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_3216);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_3217);
							}
}
