
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 3), (Arg 14))]; T (16, c);
  T (56, x)]
*/
IND_TYPE c, cp_0, c588_p_0, cp_1, c588, h, hp_0, w, wp_0, x, xp_0, x784_p_0, x785_p_0, xp_1, x784_p_1, xp_2, x784, x785, y, yp_0;
IND_TYPE y392 = 0;
IND_TYPE x786 = 0;
IND_TYPE h372 = 0;
IND_TYPE w392 = 0;
IND_TYPE c589 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6868 ,mem_vec_6869 ,mem_vec_6870 ,mem_vec_6871 ,mem_vec_6872 ,mem_vec_6873 ,mem_vec_6874 ,mem_vec_6875 ,mem_vec_6876 ,mem_vec_6877 ,mem_vec_6878 ,mem_vec_6879 ,mem_vec_6880 ,mem_vec_6881 ,mem_vec_6882 ,mem_vec_6883 ,mem_vec_6884 ,mem_vec_6885 ,mem_vec_6886 ,mem_vec_6887 ,mem_vec_6888 ,mem_vec_6889 ,mem_vec_6890 ,mem_vec_6891 ,mem_vec_6892 ,mem_vec_6893 ,mem_vec_6894 ,mem_vec_6895 ,mem_vec_6896 ,mem_vec_6897 ,mem_vec_6898 ,mem_vec_6899 ,mem_vec_6900 ,mem_vec_6901 ,mem_vec_6902 ,mem_vec_6903 ,mem_vec_6904 ,mem_vec_6905 ,mem_vec_6906 ,mem_vec_6907 ,mem_vec_6908 ,mem_vec_6909 ,mem_vec_6910 ,mem_vec_6911 ,mem_vec_6912 ,mem_vec_6913 ,mem_vec_6914 ,mem_vec_6915 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
x785 = 0;
x785_p_0 = 0;
c588 = 0;
c588_p_0 = 0;
y = 0;
yp_0 = 0;
x784 = 0;
x784_p_1 = 0;
					for (h = h372, hp_0 = 0;h < h372 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w392, wp_0 = 0;w < w392 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
							// T (x, 2) (2 / 1)
							for (x = x784, xp_2 = x784_p_1, xp_1 = x784_p_0, xp_0 = 0;x < x784 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6868 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6869 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6870 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6871 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6876 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6877 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6878 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_6879 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_6880 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_6881 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_6882 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_6883 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_6884 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_6885 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_6886 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_6887 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c588, cp_1 = c588_p_0, cp_0 = 0;c < c588 + 2;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6868);
											mem_vec_6868 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6869);
											mem_vec_6869 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6870);
											mem_vec_6870 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6871);
											mem_vec_6871 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6872);
											mem_vec_6872 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6873);
											mem_vec_6873 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6874);
											mem_vec_6874 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6875);
											mem_vec_6875 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6876);
											mem_vec_6876 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6877);
											mem_vec_6877 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6878);
											mem_vec_6878 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6879);
											mem_vec_6879 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6880);
											mem_vec_6880 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6881);
											mem_vec_6881 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6882);
											mem_vec_6882 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6883);
											mem_vec_6883 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6884);
											mem_vec_6884 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6885);
											mem_vec_6885 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6886);
											mem_vec_6886 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6887);
											mem_vec_6887 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6868);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6869);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6870);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6871);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6872);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6873);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6874);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6875);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6876);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6877);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6878);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6879);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6880);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6881);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6882);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6883);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6884);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6885);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6886);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6887);
							}
						}
					}
}
