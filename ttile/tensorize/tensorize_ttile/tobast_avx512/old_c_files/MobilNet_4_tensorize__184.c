
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (4, f); T (8, c); T (14, x); T (7, y); T (1, f)]
*/
IND_TYPE c, cp_0, c144_p_0, cp_1, c144, f, fp_0, f144_p_0, fp_1, f144, h, hp_0, x, xp_0, x144_p_0, xp_1, x144, y, yp_0;
IND_TYPE y96 = 0;
IND_TYPE x145 = 0;
IND_TYPE h72 = 0;
IND_TYPE w = 0;
IND_TYPE c145 = 0;
IND_TYPE f145 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
f144 = 0;
f144_p_0 = 0;
y = 0;
yp_0 = 0;
x144 = 0;
x144_p_0 = 0;
c144 = 0;
c144_p_0 = 0;
f = 0;
fp_1 = 0;
					for (h = h72, hp_0 = 0;h < h72 + 3;h += 1, hp_0 += 1){
						// y = 4, x = 2, h = 1, w = 3, c = 16, f = 32
						// T (x, 2) (2 / 1)
						for (x = x144, xp_1 = x144_p_0, xp_0 = 0;x < x144 + 2;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_652 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_653 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_654 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_655 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_656 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_657 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_658 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_659 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									// y = 4, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c144, cp_1 = c144_p_0, cp_0 = 0;c < c144 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_652);
										mem_vec_652 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_653);
										mem_vec_653 = vec_3;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_654);
										mem_vec_654 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_655);
										mem_vec_655 = vec_7;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_656);
										mem_vec_656 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_657);
										mem_vec_657 = vec_10;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_658);
										mem_vec_658 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_659);
										mem_vec_659 = vec_13;
										scal_4 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_16 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_652);
										mem_vec_652 = vec_14;
										vec_18 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_653);
										mem_vec_653 = vec_17;
										scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
										vec_20 = _mm512_set1_ps(scal_5);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_654);
										mem_vec_654 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_655);
										mem_vec_655 = vec_21;
										scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
										vec_23 = _mm512_set1_ps(scal_6);
										vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_656);
										mem_vec_656 = vec_22;
										vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_657);
										mem_vec_657 = vec_24;
										scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);
										vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_658);
										mem_vec_658 = vec_25;
										vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_659);
										mem_vec_659 = vec_27;
										scal_8 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);
										vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_652);
										mem_vec_652 = vec_28;
										vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_653);
										mem_vec_653 = vec_31;
										scal_9 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
										vec_34 = _mm512_set1_ps(scal_9);
										vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_654);
										mem_vec_654 = vec_33;
										vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_655);
										mem_vec_655 = vec_35;
										scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
										vec_37 = _mm512_set1_ps(scal_10);
										vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_656);
										mem_vec_656 = vec_36;
										vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_657);
										mem_vec_657 = vec_38;
										scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
										vec_40 = _mm512_set1_ps(scal_11);
										vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_658);
										mem_vec_658 = vec_39;
										vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_659);
										mem_vec_659 = vec_41;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_652);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_653);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_654);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_655);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_656);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_657);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_658);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_659);
						}
					}
}
