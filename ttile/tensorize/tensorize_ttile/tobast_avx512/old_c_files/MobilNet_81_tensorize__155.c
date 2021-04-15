
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (16, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (1, c)]
*/
IND_TYPE c, cp_0, c800_p_0, c801_p_0, cp_1, c800_p_1, cp_2, c800, c801, f, fp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y346 = 0;
IND_TYPE x484 = 0;
IND_TYPE h = 0;
IND_TYPE w348 = 0;
IND_TYPE c802 = 0;
IND_TYPE f652 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_3792 ,mem_vec_3793 ,mem_vec_3794 ,mem_vec_3795 ,mem_vec_3796 ,mem_vec_3797 ,mem_vec_3798 ,mem_vec_3799 ,mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 1) (512 / 512)
c801 = 0;
c801_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_0 = 0;
c800 = 0;
c800_p_1 = 0;
					for (w = w348, wp_0 = 0;w < w348 + 3;w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 32, f = 64
						// T (x, 7) (7 / 1)
						for (x = x484, xp_0 = 0;x < x484 + 7;x += 1, xp_0 += 1){
									mem_vec_3792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_3793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_3794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_3795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_3796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_3797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_3798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_3799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c800, cp_2 = c800_p_1, cp_1 = c800_p_0, cp_0 = 0;c < c800 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3792);
										mem_vec_3792 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3793);
										mem_vec_3793 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3794);
										mem_vec_3794 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3795);
										mem_vec_3795 = vec_7;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3796);
										mem_vec_3796 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3797);
										mem_vec_3797 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3798);
										mem_vec_3798 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3799);
										mem_vec_3799 = vec_13;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_3792);
										mem_vec_3792 = vec_14;
										vec_18 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_3793);
										mem_vec_3793 = vec_17;
										vec_20 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_3794);
										mem_vec_3794 = vec_19;
										vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_3795);
										mem_vec_3795 = vec_21;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_3796);
										mem_vec_3796 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_3797);
										mem_vec_3797 = vec_25;
										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_3798);
										mem_vec_3798 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_3799);
										mem_vec_3799 = vec_27;
										scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_3792);
										mem_vec_3792 = vec_28;
										vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_3793);
										mem_vec_3793 = vec_31;
										vec_34 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_3794);
										mem_vec_3794 = vec_33;
										vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_3795);
										mem_vec_3795 = vec_35;
										scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);
										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_3796);
										mem_vec_3796 = vec_37;
										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_3797);
										mem_vec_3797 = vec_39;
										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_3798);
										mem_vec_3798 = vec_40;
										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_3799);
										mem_vec_3799 = vec_41;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3792);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3793);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3794);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3795);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3796);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3797);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3798);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3799);
						}
					}
}
