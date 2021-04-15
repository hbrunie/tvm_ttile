
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (1, c)]
*/
IND_TYPE c, cp_0, c792_p_0, c793_p_0, cp_1, c792_p_1, cp_2, c792, c793, f, fp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y342 = 0;
IND_TYPE x480 = 0;
IND_TYPE h = 0;
IND_TYPE w344 = 0;
IND_TYPE c794 = 0;
IND_TYPE f648 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_3752 ,mem_vec_3753 ,mem_vec_3754 ,mem_vec_3755 ,mem_vec_3756 ,mem_vec_3757 ,mem_vec_3758 ,mem_vec_3759 ,mem_vec_3760 ,mem_vec_3761 ,mem_vec_3762 ,mem_vec_3763 ,mem_vec_3764 ,mem_vec_3765 ,mem_vec_3766 ,mem_vec_3767 ,mem_vec_3768 ,mem_vec_3769 ,mem_vec_3770 ,mem_vec_3771 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 1) (512 / 512)
c793 = 0;
c793_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_0 = 0;
c792 = 0;
c792_p_1 = 0;
					for (w = w344, wp_0 = 0;w < w344 + 3;w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 256, f = 64
						// T (x, 7) (7 / 1)
						for (x = x480, xp_0 = 0;x < x480 + 7;x += 1, xp_0 += 1){
									mem_vec_3752 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_3753 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_3754 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_3755 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_3756 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_3757 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_3758 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_3759 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c792, cp_2 = c792_p_1, cp_1 = c792_p_0, cp_0 = 0;c < c792 + 256;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3752);
										mem_vec_3752 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3753);
										mem_vec_3753 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3754);
										mem_vec_3754 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3755);
										mem_vec_3755 = vec_7;
										scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3756);
										mem_vec_3756 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3757);
										mem_vec_3757 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3758);
										mem_vec_3758 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3759);
										mem_vec_3759 = vec_13;
										scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_3752);
										mem_vec_3752 = vec_14;
										vec_18 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_3753);
										mem_vec_3753 = vec_17;
										vec_20 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_3754);
										mem_vec_3754 = vec_19;
										vec_22 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_3755);
										mem_vec_3755 = vec_21;
										scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_3756);
										mem_vec_3756 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_3757);
										mem_vec_3757 = vec_25;
										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_3758);
										mem_vec_3758 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_3759);
										mem_vec_3759 = vec_27;
										scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_3752);
										mem_vec_3752 = vec_28;
										vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_3753);
										mem_vec_3753 = vec_31;
										vec_34 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_3754);
										mem_vec_3754 = vec_33;
										vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_3755);
										mem_vec_3755 = vec_35;
										scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);
										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_3756);
										mem_vec_3756 = vec_37;
										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_3757);
										mem_vec_3757 = vec_39;
										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_3758);
										mem_vec_3758 = vec_40;
										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_3759);
										mem_vec_3759 = vec_41;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3752);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3753);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3754);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3755);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3756);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3757);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3758);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3759);
						}
					}
}
