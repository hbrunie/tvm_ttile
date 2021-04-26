
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (4, f); T (1, x); T (1, y); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]]
*/
IND_TYPE c, cp_0, c567_p_0, cp_1, c567, f, fp_0, x, xp_0, x756_p_0, x757_p_0, xp_1, x756_p_1, xp_2, x756, x757, y, yp_0, y567_p_0, yp_1, y567;
IND_TYPE y568 = 0;
IND_TYPE x758 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c568 = 0;
IND_TYPE f378 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8852 ,mem_vec_8853 ,mem_vec_8854 ,mem_vec_8855 ,mem_vec_8856 ,mem_vec_8857 ,mem_vec_8858 ,mem_vec_8859 ,mem_vec_8860 ,mem_vec_8861 ,mem_vec_8862 ,mem_vec_8863 ,mem_vec_8864 ,mem_vec_8865 ,mem_vec_8866 ,mem_vec_8867 ,mem_vec_8868 ,mem_vec_8869 ,mem_vec_8870 ,mem_vec_8871 ,mem_vec_8872 ,mem_vec_8873 ,mem_vec_8874 ,mem_vec_8875 ,mem_vec_8876 ,mem_vec_8877 ,mem_vec_8878 ,mem_vec_8879 ,mem_vec_8880 ,mem_vec_8881 ,mem_vec_8882 ,mem_vec_8883 ,mem_vec_8884 ,mem_vec_8885 ,mem_vec_8886 ,mem_vec_8887 ,mem_vec_8888 ,mem_vec_8889 ,mem_vec_8890 ,mem_vec_8891 ,mem_vec_8892 ,mem_vec_8893 ,mem_vec_8894 ,mem_vec_8895 ,mem_vec_8896 ,mem_vec_8897 ,mem_vec_8898 ,mem_vec_8899 ,mem_vec_8900 ,mem_vec_8901 ,mem_vec_8902 ,mem_vec_8903 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y567 = 0;
y567_p_0 = 0;
x757 = 0;
x757_p_0 = 0;
y = 0;
yp_1 = 0;
x756 = 0;
x756_p_1 = 0;
f = 0;
fp_0 = 0;
c567 = 0;
c567_p_0 = 0;
							for (x = x756, xp_2 = x756_p_1, xp_1 = x756_p_0, xp_0 = 0;x < x756 + 34;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8852 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_8853 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_8854 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_8855 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_8856 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_8857 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_8858 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_8859 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_8860 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_8861 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_8862 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_8863 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_8864 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_8865 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_8866 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_8867 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_8868 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_8869 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_8870 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_8871 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_8872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_8873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_8874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_8875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c567, cp_1 = c567_p_0, cp_0 = 0;c < c567 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8852);
											mem_vec_8852 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8853);
											mem_vec_8853 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8854);
											mem_vec_8854 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8855);
											mem_vec_8855 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8856);
											mem_vec_8856 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8857);
											mem_vec_8857 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8858);
											mem_vec_8858 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8859);
											mem_vec_8859 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8860);
											mem_vec_8860 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8861);
											mem_vec_8861 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8862);
											mem_vec_8862 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8863);
											mem_vec_8863 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8864);
											mem_vec_8864 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8865);
											mem_vec_8865 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8866);
											mem_vec_8866 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8867);
											mem_vec_8867 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8868);
											mem_vec_8868 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8869);
											mem_vec_8869 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8870);
											mem_vec_8870 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8871);
											mem_vec_8871 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8872);
											mem_vec_8872 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8873);
											mem_vec_8873 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8874);
											mem_vec_8874 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8875);
											mem_vec_8875 = vec_37;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8852);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8853);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8854);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8855);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8856);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8857);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8858);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8859);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8860);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8861);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8862);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8863);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8864);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8865);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8866);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8867);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8868);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8869);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8870);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_8871);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_8872);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_8873);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_8874);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_8875);
							}
}
