
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (512, c);
  T (1, y); T (16, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, x, xp_0, y, yp_0, y42_p_0, yp_1, y42;
IND_TYPE y43 = 0;
IND_TYPE x28 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c43 = 0;
IND_TYPE f28 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,mem_vec_482 ,mem_vec_483 ,mem_vec_484 ,mem_vec_485 ,mem_vec_486 ,mem_vec_487 ,mem_vec_488 ,mem_vec_489 ,mem_vec_490 ,mem_vec_491 ,mem_vec_492 ,mem_vec_493 ,mem_vec_494 ,mem_vec_495 ,mem_vec_496 ,mem_vec_497 ,mem_vec_498 ,mem_vec_499 ,mem_vec_500 ,mem_vec_501 ,mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y42 = 0;
y42_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
c42 = 0;
c42_p_0 = 0;
					for (x = x28, xp_0 = 0;x < x28 + 17;x += 1, xp_0 += 1){
								mem_vec_476 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_477 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_478 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_479 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_480 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_481 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_482 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_483 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_484 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_485 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_486 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_487 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_488 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_489 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_490 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_491 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (c, 2) (2 / 1)
								for (c = c42, cp_1 = c42_p_0, cp_0 = 0;c < c42 + 2;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_476);
									mem_vec_476 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_477);
									mem_vec_477 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_478);
									mem_vec_478 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_479);
									mem_vec_479 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_480);
									mem_vec_480 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_481);
									mem_vec_481 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_482);
									mem_vec_482 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_483);
									mem_vec_483 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_484);
									mem_vec_484 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_485);
									mem_vec_485 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_486);
									mem_vec_486 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_487);
									mem_vec_487 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_488);
									mem_vec_488 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_489);
									mem_vec_489 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_490);
									mem_vec_490 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_491);
									mem_vec_491 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_476);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_477);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_478);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_479);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_480);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_481);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_482);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_483);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_484);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_485);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_486);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_487);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_488);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_489);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_490);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_491);
					}
}
