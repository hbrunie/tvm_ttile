
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (64, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (14, x); T (7, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c97_p_0, cp_1, c97, f, fp_0, f97_p_0, fp_1, f97, x, xp_0, x108_p_0, xp_1, x108, y, yp_0;
IND_TYPE y72 = 0;
IND_TYPE x109 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c98 = 0;
IND_TYPE f98 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
f97 = 0;
f97_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_0 = 0;
x108 = 0;
x108_p_0 = 0;
c97 = 0;
c97_p_0 = 0;
					for (x = x108, xp_1 = x108_p_0, xp_0 = 0;x < x108 + 2;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								mem_vec_636 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_637 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_638 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
								mem_vec_639 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c97, cp_1 = c97_p_0, cp_0 = 0;c < c97 + 64;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_624);
									mem_vec_624 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_625);
									mem_vec_625 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_626);
									mem_vec_626 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_627);
									mem_vec_627 = vec_7;
									scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_628);
									mem_vec_628 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_629);
									mem_vec_629 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_630);
									mem_vec_630 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_631);
									mem_vec_631 = vec_13;
									scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_632);
									mem_vec_632 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_633);
									mem_vec_633 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_634);
									mem_vec_634 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_635);
									mem_vec_635 = vec_18;
									scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);
									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_636);
									mem_vec_636 = vec_19;
									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_637);
									mem_vec_637 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_638);
									mem_vec_638 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_639);
									mem_vec_639 = vec_23;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_624);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_625);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_626);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_627);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_628);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_629);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_630);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_631);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_632);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_633);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_634);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_635);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_636);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_637);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_638);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_639);
					}
}
