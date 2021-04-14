void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, f); T (1, c); T (14, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, f)]
*/
IND_TYPE c, cp_0, c894_p_0, cp_1, c894, f, fp_0, f894_p_0, fp_1, f894, w, wp_0, x, xp_0, x894_p_0, xp_1, x894, y, yp_0;
IND_TYPE y596 = 0;
IND_TYPE x895 = 0;
IND_TYPE h = 0;
IND_TYPE w560 = 0;
IND_TYPE c895 = 0;
IND_TYPE f895 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8664 ,mem_vec_8665 ,mem_vec_8666 ,mem_vec_8667 ,mem_vec_8668 ,mem_vec_8669 ,mem_vec_8670 ,mem_vec_8671 ,mem_vec_8672 ,mem_vec_8673 ,mem_vec_8674 ,mem_vec_8675 ,mem_vec_8676 ,mem_vec_8677 ,mem_vec_8678 ,mem_vec_8679 ,mem_vec_8680 ,mem_vec_8681 ,mem_vec_8682 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 8) (128 / 16)
f894 = 0;
f894_p_0 = 0;
y = 0;
yp_0 = 0;
x894 = 0;
x894_p_0 = 0;
c894 = 0;
c894_p_0 = 0;
f = 0;
fp_1 = 0;
						for (w = w560, wp_0 = 0;w < w560 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 64, f = 16
							// T (x, 2) (2 / 1)
							for (x = x894, xp_1 = x894_p_0, xp_0 = 0;x < x894 + 2;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8673 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_8674 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_8675 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_8676 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_8677 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_8678 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_8679 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_8680 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_8681 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_8682 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
										// T (c, 64) (64 / 1)
										for (c = c894, cp_1 = c894_p_0, cp_0 = 0;c < c894 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8673);
											mem_vec_8673 = vec_0;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8674);
											mem_vec_8674 = vec_3;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8675);
											mem_vec_8675 = vec_5;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8676);
											mem_vec_8676 = vec_7;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8677);
											mem_vec_8677 = vec_9;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8678);
											mem_vec_8678 = vec_11;
											scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8679);
											mem_vec_8679 = vec_13;
											scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8680);
											mem_vec_8680 = vec_15;
											scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8681);
											mem_vec_8681 = vec_17;
											scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8682);
											mem_vec_8682 = vec_19;
											scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 1) + c];
											vec_22 = _mm512_set1_ps(scal_10);
											vec_23 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_21 = _mm512_fmadd_ps(vec_22, vec_23, mem_vec_8673);
											mem_vec_8673 = vec_21;
											scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_23, mem_vec_8674);
											mem_vec_8674 = vec_24;
											scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_23, mem_vec_8675);
											mem_vec_8675 = vec_26;
											scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_8676);
											mem_vec_8676 = vec_28;
											scal_14 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_30 = _mm512_fmadd_ps(vec_31, vec_23, mem_vec_8677);
											mem_vec_8677 = vec_30;
											scal_15 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_23, mem_vec_8678);
											mem_vec_8678 = vec_32;
											scal_16 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_23, mem_vec_8679);
											mem_vec_8679 = vec_34;
											scal_17 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);
											vec_36 = _mm512_fmadd_ps(vec_37, vec_23, mem_vec_8680);
											mem_vec_8680 = vec_36;
											scal_18 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_23, mem_vec_8681);
											mem_vec_8681 = vec_38;
											scal_19 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_23, mem_vec_8682);
											mem_vec_8682 = vec_40;
											scal_20 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h + 2) + c];
											vec_43 = _mm512_set1_ps(scal_20);
											vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_42 = _mm512_fmadd_ps(vec_43, vec_44, mem_vec_8673);
											mem_vec_8673 = vec_42;
											scal_21 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_21);
											vec_45 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_8674);
											mem_vec_8674 = vec_45;
											scal_22 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_22);
											vec_47 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_8675);
											mem_vec_8675 = vec_47;
											scal_23 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h + 2) + c];
											vec_50 = _mm512_set1_ps(scal_23);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_44, mem_vec_8676);
											mem_vec_8676 = vec_49;
											scal_24 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_24);
											vec_51 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_8677);
											mem_vec_8677 = vec_51;
											scal_25 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_44, mem_vec_8678);
											mem_vec_8678 = vec_53;
											scal_26 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_44, mem_vec_8679);
											mem_vec_8679 = vec_55;
											scal_27 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_8680);
											mem_vec_8680 = vec_57;
											scal_28 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);
											vec_59 = _mm512_fmadd_ps(vec_60, vec_44, mem_vec_8681);
											mem_vec_8681 = vec_59;
											scal_29 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_44, mem_vec_8682);
											mem_vec_8682 = vec_61;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8673);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8674);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8675);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8676);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8677);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8678);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8679);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8680);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8681);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8682);
							}
						}
}
