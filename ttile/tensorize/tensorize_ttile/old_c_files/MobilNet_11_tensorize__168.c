
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (28, x);
  Lambda_apply y [((Iter 7), (Arg 8)); ((Iter 4), (Arg 14))]; T (4, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c384_p_0, cp_1, c384, h, hp_0, w, wp_0, x, xp_0, x512_p_0, x513_p_0, xp_1, x512_p_1, xp_2, x512, x513, y, yp_0;
IND_TYPE y256 = 0;
IND_TYPE x514 = 0;
IND_TYPE h236 = 0;
IND_TYPE w256 = 0;
IND_TYPE c385 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3816 ,mem_vec_3817 ,mem_vec_3818 ,mem_vec_3819 ,mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,mem_vec_3836 ,mem_vec_3837 ,mem_vec_3838 ,mem_vec_3839 ,mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,mem_vec_3852 ,mem_vec_3853 ,mem_vec_3854 ,mem_vec_3855 ,mem_vec_3856 ,mem_vec_3857 ,mem_vec_3858 ,mem_vec_3859 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
x513 = 0;
x513_p_0 = 0;
c384 = 0;
c384_p_0 = 0;
y = 0;
yp_0 = 0;
x512 = 0;
x512_p_1 = 0;
					for (h = h236, hp_0 = 0;h < h236 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w256, wp_0 = 0;w < w256 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
							// T (x, 1) (1 / 1)
							for (x = x512, xp_2 = x512_p_1, xp_1 = x512_p_0, xp_0 = 0;x < x512 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3816 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_3817 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_3818 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_3819 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_3820 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_3821 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_3822 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_3823 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_3824 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_3825 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_3826 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_3827 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_3828 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_3829 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_3830 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_3831 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c384, cp_1 = c384_p_0, cp_0 = 0;c < c384 + 8;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3816);
											mem_vec_3816 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3817);
											mem_vec_3817 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3818);
											mem_vec_3818 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3819);
											mem_vec_3819 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3820);
											mem_vec_3820 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3821);
											mem_vec_3821 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3822);
											mem_vec_3822 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3823);
											mem_vec_3823 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3824);
											mem_vec_3824 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3825);
											mem_vec_3825 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3826);
											mem_vec_3826 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3827);
											mem_vec_3827 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3828);
											mem_vec_3828 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3829);
											mem_vec_3829 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3830);
											mem_vec_3830 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3831);
											mem_vec_3831 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3816);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3817);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3818);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3819);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3820);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3821);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3822);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3823);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3824);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3825);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3826);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3827);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3828);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3829);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3830);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3831);
							}
						}
					}
}
