void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (4, f); T (4, c); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 5)); ((Iter 1), (Arg 8))]; T (2, f)]
*/
IND_TYPE c, cp_0, c702_p_0, cp_1, c702, f, fp_0, f684_p_0, fp_1, f684, h, hp_0, x, xp_0, x696_p_0, xp_1, x696, y, yp_0;
IND_TYPE y464 = 0;
IND_TYPE x697 = 0;
IND_TYPE h326 = 0;
IND_TYPE w = 0;
IND_TYPE c703 = 0;
IND_TYPE f685 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5906 ,mem_vec_5907 ,mem_vec_5908 ,mem_vec_5909 ,mem_vec_5910 ,mem_vec_5911 ,mem_vec_5912 ,mem_vec_5913 ,mem_vec_5914 ,mem_vec_5915 ,mem_vec_5916 ,mem_vec_5917 ,mem_vec_5918 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f684 = 0;
f684_p_0 = 0;
y = 0;
yp_0 = 0;
x696 = 0;
x696_p_0 = 0;
c702 = 0;
c702_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h326, hp_0 = 0;h < h326 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 32, f = 16
							// T (x, 28) (28 / 1)
							for (x = x696, xp_1 = x696_p_0, xp_0 = 0;x < x696 + 28;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5911 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5912 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5913 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5914 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5915 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5916 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5917 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5918 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c702, cp_1 = c702_p_0, cp_0 = 0;c < c702 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5911);
											mem_vec_5911 = vec_0;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_5912);
											mem_vec_5912 = vec_3;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5913);
											mem_vec_5913 = vec_5;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_5914);
											mem_vec_5914 = vec_7;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5915);
											mem_vec_5915 = vec_9;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5916);
											mem_vec_5916 = vec_11;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_5917);
											mem_vec_5917 = vec_13;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_5918);
											mem_vec_5918 = vec_15;
											scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_19 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_5911);
											mem_vec_5911 = vec_17;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_21 = _mm512_set1_ps(scal_9);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_19, mem_vec_5912);
											mem_vec_5912 = vec_20;
											scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_23 = _mm512_set1_ps(scal_10);
											vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_5913);
											mem_vec_5913 = vec_22;
											scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_25 = _mm512_set1_ps(scal_11);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_19, mem_vec_5914);
											mem_vec_5914 = vec_24;
											scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_27 = _mm512_set1_ps(scal_12);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_19, mem_vec_5915);
											mem_vec_5915 = vec_26;
											scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
											vec_29 = _mm512_set1_ps(scal_13);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_5916);
											mem_vec_5916 = vec_28;
											scal_14 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_30 = _mm512_fmadd_ps(vec_31, vec_19, mem_vec_5917);
											mem_vec_5917 = vec_30;
											scal_15 = input[strideA1 * (x + w + 1) + strideA2 * (y + 7 + h) + c];
											vec_33 = _mm512_set1_ps(scal_15);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_19, mem_vec_5918);
											mem_vec_5918 = vec_32;
											scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5911);
											mem_vec_5911 = vec_34;
											scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_17);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_5912);
											mem_vec_5912 = vec_37;
											scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_40 = _mm512_set1_ps(scal_18);
											vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_5913);
											mem_vec_5913 = vec_39;
											scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_42 = _mm512_set1_ps(scal_19);
											vec_41 = _mm512_fmadd_ps(vec_42, vec_36, mem_vec_5914);
											mem_vec_5914 = vec_41;
											scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_44 = _mm512_set1_ps(scal_20);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5915);
											mem_vec_5915 = vec_43;
											scal_21 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
											vec_46 = _mm512_set1_ps(scal_21);
											vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_5916);
											mem_vec_5916 = vec_45;
											scal_22 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
											vec_48 = _mm512_set1_ps(scal_22);
											vec_47 = _mm512_fmadd_ps(vec_48, vec_36, mem_vec_5917);
											mem_vec_5917 = vec_47;
											scal_23 = input[strideA1 * (x + w + 2) + strideA2 * (y + 7 + h) + c];
											vec_50 = _mm512_set1_ps(scal_23);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_5918);
											mem_vec_5918 = vec_49;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5911);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5912);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5913);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5914);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5915);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5916);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5917);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5918);
							}
						}
}
