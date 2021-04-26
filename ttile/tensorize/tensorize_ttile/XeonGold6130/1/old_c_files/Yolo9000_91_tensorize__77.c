
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (2, c);
  T (4, f); T (1, x); T (2, y); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]]
*/
IND_TYPE c, cp_0, c342_p_0, cp_1, c342, f, fp_0, x, xp_0, x456_p_0, x457_p_0, xp_1, x456_p_1, xp_2, x456, x457, y, yp_0, y342_p_0, yp_1, y342;
IND_TYPE y343 = 0;
IND_TYPE x458 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c343 = 0;
IND_TYPE f228 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5408 ,mem_vec_5409 ,mem_vec_5410 ,mem_vec_5411 ,mem_vec_5412 ,mem_vec_5413 ,mem_vec_5414 ,mem_vec_5415 ,mem_vec_5416 ,mem_vec_5417 ,mem_vec_5418 ,mem_vec_5419 ,mem_vec_5420 ,mem_vec_5421 ,mem_vec_5422 ,mem_vec_5423 ,mem_vec_5424 ,mem_vec_5425 ,mem_vec_5426 ,mem_vec_5427 ,mem_vec_5428 ,mem_vec_5429 ,mem_vec_5430 ,mem_vec_5431 ,mem_vec_5432 ,mem_vec_5433 ,mem_vec_5434 ,mem_vec_5435 ,mem_vec_5436 ,mem_vec_5437 ,mem_vec_5438 ,mem_vec_5439 ,mem_vec_5440 ,mem_vec_5441 ,mem_vec_5442 ,mem_vec_5443 ,mem_vec_5444 ,mem_vec_5445 ,mem_vec_5446 ,mem_vec_5447 ,mem_vec_5448 ,mem_vec_5449 ,mem_vec_5450 ,mem_vec_5451 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y342 = 0;
y342_p_0 = 0;
x457 = 0;
x457_p_0 = 0;
y = 0;
yp_1 = 0;
x456 = 0;
x456_p_1 = 0;
f = 0;
fp_0 = 0;
c342 = 0;
c342_p_0 = 0;
							for (x = x456, xp_2 = x456_p_1, xp_1 = x456_p_0, xp_0 = 0;x < x456 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5408 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5409 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5410 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5411 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5412 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5413 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5414 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5415 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5416 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5417 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5418 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5419 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_5422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_5423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_5424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_5425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_5426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_5427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c342, cp_1 = c342_p_0, cp_0 = 0;c < c342 + 128;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5408);
											mem_vec_5408 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5409);
											mem_vec_5409 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5410);
											mem_vec_5410 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5411);
											mem_vec_5411 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5412);
											mem_vec_5412 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5413);
											mem_vec_5413 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5414);
											mem_vec_5414 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5415);
											mem_vec_5415 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5416);
											mem_vec_5416 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5417);
											mem_vec_5417 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5418);
											mem_vec_5418 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5419);
											mem_vec_5419 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5420);
											mem_vec_5420 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5421);
											mem_vec_5421 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5422);
											mem_vec_5422 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5423);
											mem_vec_5423 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5424);
											mem_vec_5424 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5425);
											mem_vec_5425 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5426);
											mem_vec_5426 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5427);
											mem_vec_5427 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5408);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5409);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5410);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5411);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5412);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5413);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5414);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5415);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5416);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5417);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5418);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5419);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5420);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5421);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5422);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5423);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5424);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5425);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5426);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5427);
							}
}
