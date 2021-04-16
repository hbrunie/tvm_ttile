
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (28, x); T (7, y); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c118_p_0, cp_1, c118, f, fp_0, f118_p_0, fp_1, f118, x, xp_0, x129_p_0, xp_1, x129, y, yp_0;
IND_TYPE y86 = 0;
IND_TYPE x130 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c119 = 0;
IND_TYPE f119 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 1) (128 / 128)
f118 = 0;
f118_p_0 = 0;
f = 0;
fp_1 = 0;
y = 0;
yp_0 = 0;
x129 = 0;
x129_p_0 = 0;
c118 = 0;
c118_p_0 = 0;
					for (x = x129, xp_1 = x129_p_0, xp_0 = 0;x < x129 + 1;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_736 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_737 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_738 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_739 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_740 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_741 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_742 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_743 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_744 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_745 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_746 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_747 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								mem_vec_748 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_749 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_750 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
								mem_vec_751 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
								// y = 4, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c118, cp_1 = c118_p_0, cp_0 = 0;c < c118 + 32;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_736);
									mem_vec_736 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_737);
									mem_vec_737 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_738);
									mem_vec_738 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_739);
									mem_vec_739 = vec_7;
									scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_740);
									mem_vec_740 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_741);
									mem_vec_741 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_742);
									mem_vec_742 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_743);
									mem_vec_743 = vec_13;
									scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_744);
									mem_vec_744 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_745);
									mem_vec_745 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_746);
									mem_vec_746 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_747);
									mem_vec_747 = vec_18;
									scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);
									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_748);
									mem_vec_748 = vec_19;
									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_749);
									mem_vec_749 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_750);
									mem_vec_750 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_751);
									mem_vec_751 = vec_23;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_736);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_737);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_738);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_739);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_740);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_741);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_742);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_743);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_744);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_745);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_746);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_747);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_748);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_749);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_750);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_751);
					}
}
