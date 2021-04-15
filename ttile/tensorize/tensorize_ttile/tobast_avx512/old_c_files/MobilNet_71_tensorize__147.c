
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, c); T (8, f); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 1), (Arg 5))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1476_p_0, c1477_p_0, cp_1, c1476_p_1, cp_2, c1476, c1477, f, fp_0, h, hp_0, x, xp_0, x1124_p_0, xp_1, x1124, y, yp_0;
IND_TYPE y752 = 0;
IND_TYPE x1125 = 0;
IND_TYPE h692 = 0;
IND_TYPE w = 0;
IND_TYPE c1478 = 0;
IND_TYPE f1320 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8508 ,mem_vec_8509 ,mem_vec_8510 ,mem_vec_8511 ,mem_vec_8512 ,mem_vec_8513 ,mem_vec_8514 ,mem_vec_8515 ,mem_vec_8516 ,mem_vec_8517 ,mem_vec_8518 ,mem_vec_8519 ,mem_vec_8520 ,mem_vec_8521 ,mem_vec_8522 ,mem_vec_8523 ,mem_vec_8524 ,mem_vec_8525 ,mem_vec_8526 ,mem_vec_8527 ,mem_vec_8528 ,mem_vec_8529 ,mem_vec_8530 ,mem_vec_8531 ,mem_vec_8532 ,mem_vec_8533 ,mem_vec_8534 ,mem_vec_8535 ,mem_vec_8536 ,mem_vec_8537 ,mem_vec_8538 ,mem_vec_8539 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 2) (512 / 256)
c1477 = 0;
c1477_p_0 = 0;
y = 0;
yp_0 = 0;
x1124 = 0;
x1124_p_0 = 0;
f = 0;
fp_0 = 0;
c1476 = 0;
c1476_p_1 = 0;
						for (h = h692, hp_0 = 0;h < h692 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1124, xp_1 = x1124_p_0, xp_0 = 0;x < x1124 + 7;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8508 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_8509 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_8510 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_8511 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_8512 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_8513 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_8514 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_8515 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_8516 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_8517 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_8518 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_8519 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c1476, cp_2 = c1476_p_1, cp_1 = c1476_p_0, cp_0 = 0;c < c1476 + 64;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8508);
											mem_vec_8508 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8509);
											mem_vec_8509 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8510);
											mem_vec_8510 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8511);
											mem_vec_8511 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8512);
											mem_vec_8512 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8513);
											mem_vec_8513 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8514);
											mem_vec_8514 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8515);
											mem_vec_8515 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8516);
											mem_vec_8516 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8517);
											mem_vec_8517 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8518);
											mem_vec_8518 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8519);
											mem_vec_8519 = vec_18;
											scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_21 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_8508);
											mem_vec_8508 = vec_19;
											vec_23 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_8509);
											mem_vec_8509 = vec_22;
											vec_25 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_8510);
											mem_vec_8510 = vec_24;
											vec_27 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_8511);
											mem_vec_8511 = vec_26;
											scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_8512);
											mem_vec_8512 = vec_28;
											vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_8513);
											mem_vec_8513 = vec_30;
											vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_8514);
											mem_vec_8514 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_8515);
											mem_vec_8515 = vec_32;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);
											vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_8516);
											mem_vec_8516 = vec_33;
											vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_8517);
											mem_vec_8517 = vec_35;
											vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_8518);
											mem_vec_8518 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_8519);
											mem_vec_8519 = vec_37;
											scal_6 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_8508);
											mem_vec_8508 = vec_38;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_8509);
											mem_vec_8509 = vec_41;
											vec_44 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_8510);
											mem_vec_8510 = vec_43;
											vec_46 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_8511);
											mem_vec_8511 = vec_45;
											scal_7 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_48 = _mm512_set1_ps(scal_7);
											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_8512);
											mem_vec_8512 = vec_47;
											vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_8513);
											mem_vec_8513 = vec_49;
											vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_8514);
											mem_vec_8514 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_8515);
											mem_vec_8515 = vec_51;
											scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_53 = _mm512_set1_ps(scal_8);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_8516);
											mem_vec_8516 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_8517);
											mem_vec_8517 = vec_54;
											vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_8518);
											mem_vec_8518 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_8519);
											mem_vec_8519 = vec_56;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8508);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8509);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_8510);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_8511);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8512);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8513);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_8514);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_8515);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8516);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8517);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_8518);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_8519);
							}
						}
}
