
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (2, f); T (1, x); T (4, y); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]]
*/
IND_TYPE c, cp_0, c495_p_0, cp_1, c495, f, fp_0, x, xp_0, x660_p_0, x661_p_0, xp_1, x660_p_1, xp_2, x660, x661, y, yp_0, y495_p_0, yp_1, y495;
IND_TYPE y496 = 0;
IND_TYPE x662 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c496 = 0;
IND_TYPE f330 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_6420 ,mem_vec_6421 ,mem_vec_6422 ,mem_vec_6423 ,mem_vec_6424 ,mem_vec_6425 ,mem_vec_6426 ,mem_vec_6427 ,mem_vec_6428 ,mem_vec_6429 ,mem_vec_6430 ,mem_vec_6431 ,mem_vec_6432 ,mem_vec_6433 ,mem_vec_6434 ,mem_vec_6435 ,mem_vec_6436 ,mem_vec_6437 ,mem_vec_6438 ,mem_vec_6439 ,mem_vec_6440 ,mem_vec_6441 ,mem_vec_6442 ,mem_vec_6443 ,mem_vec_6444 ,mem_vec_6445 ,mem_vec_6446 ,mem_vec_6447 ,mem_vec_6448 ,mem_vec_6449 ,mem_vec_6450 ,mem_vec_6451 ,mem_vec_6452 ,mem_vec_6453 ,mem_vec_6454 ,mem_vec_6455 ,mem_vec_6456 ,mem_vec_6457 ,mem_vec_6458 ,mem_vec_6459 ,mem_vec_6460 ,mem_vec_6461 ,mem_vec_6462 ,mem_vec_6463 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y495 = 0;
y495_p_0 = 0;
x661 = 0;
x661_p_0 = 0;
y = 0;
yp_1 = 0;
x660 = 0;
x660_p_1 = 0;
f = 0;
fp_0 = 0;
c495 = 0;
c495_p_0 = 0;
							for (x = x660, xp_2 = x660_p_1, xp_1 = x660_p_0, xp_0 = 0;x < x660 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_6423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_6424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_6427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_6428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_6431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_6432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_6435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_6436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_6439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c495, cp_1 = c495_p_0, cp_0 = 0;c < c495 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6420);
											mem_vec_6420 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6421);
											mem_vec_6421 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6422);
											mem_vec_6422 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6423);
											mem_vec_6423 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6424);
											mem_vec_6424 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6425);
											mem_vec_6425 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6426);
											mem_vec_6426 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6427);
											mem_vec_6427 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6428);
											mem_vec_6428 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6429);
											mem_vec_6429 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6430);
											mem_vec_6430 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6431);
											mem_vec_6431 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6432);
											mem_vec_6432 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6433);
											mem_vec_6433 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6434);
											mem_vec_6434 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6435);
											mem_vec_6435 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6436);
											mem_vec_6436 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6437);
											mem_vec_6437 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6438);
											mem_vec_6438 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6439);
											mem_vec_6439 = vec_28;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6420);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6421);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_6422);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_6423);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6424);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6425);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_6426);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_6427);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6428);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6429);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_6430);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_6431);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6432);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6433);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_6434);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_6435);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6436);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6437);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_6438);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_6439);
							}
}
