
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (1, c); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c39_p_0, cp_1, c39, f, fp_0, x, xp_0, x39_p_0, xp_1, x39, y, yp_0, y39_p_0, yp_1, y39;
IND_TYPE y40 = 0;
IND_TYPE x40 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c40 = 0;
IND_TYPE f26 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y39 = 0;
y39_p_0 = 0;
x39 = 0;
x39_p_0 = 0;
c39 = 0;
c39_p_0 = 0;
			for (f = f26, fp_0 = 0;f < f26 + 512;f += 32, fp_0 += 32){
					for (y = y39, yp_1 = y39_p_0, yp_0 = 0;y < y39 + 12;y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
						// T (x, 17) (17 / 1)
						for (x = x39, xp_1 = x39_p_0, xp_0 = 0;x < x39 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_468 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_469 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_470 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_471 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_472 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_473 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_474 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_475 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_476 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_477 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_478 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_479 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_480 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_481 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_482 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_483 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
									// T (c, 1024) (1024 / 1)
									for (c = c39, cp_1 = c39_p_0, cp_0 = 0;c < c39 + 1024;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_468);
										mem_vec_468 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_469);
										mem_vec_469 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_470);
										mem_vec_470 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_471);
										mem_vec_471 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_472);
										mem_vec_472 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_473);
										mem_vec_473 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_474);
										mem_vec_474 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_475);
										mem_vec_475 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_476);
										mem_vec_476 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_477);
										mem_vec_477 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_478);
										mem_vec_478 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_479);
										mem_vec_479 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_480);
										mem_vec_480 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_481);
										mem_vec_481 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_482);
										mem_vec_482 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_483);
										mem_vec_483 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_468);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_469);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_470);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_471);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_472);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_473);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_474);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_475);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_476);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_477);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_478);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_479);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_480);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_481);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_482);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_483);
						}
					}
					for (y = y39 + 12, yp_1 = y39_p_0, yp_0 = 0;y < y39 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
						// T (x, 17) (17 / 1)
						for (x = x39, xp_1 = x39_p_0, xp_0 = 0;x < x39 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_484 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_485 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_486 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_487 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_488 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_489 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_490 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_491 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_492 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_493 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_494 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_495 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_496 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_497 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_498 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_499 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_500 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_501 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_502 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_503 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 32
									// T (c, 1024) (1024 / 1)
									for (c = c39, cp_1 = c39_p_0, cp_0 = 0;c < c39 + 1024;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_484);
										mem_vec_484 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_485);
										mem_vec_485 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_486);
										mem_vec_486 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_487);
										mem_vec_487 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_488);
										mem_vec_488 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_489);
										mem_vec_489 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_490);
										mem_vec_490 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_491);
										mem_vec_491 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_492);
										mem_vec_492 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_493);
										mem_vec_493 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_494);
										mem_vec_494 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_495);
										mem_vec_495 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_496);
										mem_vec_496 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_497);
										mem_vec_497 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_498);
										mem_vec_498 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_499);
										mem_vec_499 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_500);
										mem_vec_500 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_501);
										mem_vec_501 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_502);
										mem_vec_502 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_503);
										mem_vec_503 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_484);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_485);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_486);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_487);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_488);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_489);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_490);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_491);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_492);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_493);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_494);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_495);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_496);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_497);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_498);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_499);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_500);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_501);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_502);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_503);
						}
					}
			}
}
