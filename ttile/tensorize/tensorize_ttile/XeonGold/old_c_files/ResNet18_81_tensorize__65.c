
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (4, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c372_p_0, cp_1, c372, f, fp_0, f372_p_0, fp_1, f372, w, wp_0, x, xp_0, x352_p_0, xp_1, x352, y, yp_0;
IND_TYPE y248 = 0;
IND_TYPE x353 = 0;
IND_TYPE h = 0;
IND_TYPE w215 = 0;
IND_TYPE c373 = 0;
IND_TYPE f373 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3544 ,mem_vec_3545 ,mem_vec_3546 ,mem_vec_3547 ,mem_vec_3548 ,mem_vec_3549 ,mem_vec_3550 ,mem_vec_3551 ,mem_vec_3552 ,mem_vec_3553 ,mem_vec_3554 ,mem_vec_3555 ,mem_vec_3556 ,mem_vec_3557 ,mem_vec_3558 ,mem_vec_3559 ,mem_vec_3560 ,mem_vec_3561 ,mem_vec_3562 ,mem_vec_3563 ,mem_vec_3564 ,mem_vec_3565 ,mem_vec_3566 ,mem_vec_3567 ,mem_vec_3568 ,mem_vec_3569 ,mem_vec_3570 ,mem_vec_3571 ,mem_vec_3572 ,mem_vec_3573 ,mem_vec_3574 ,mem_vec_3575 ,mem_vec_3576 ,mem_vec_3577 ,mem_vec_3578 ,mem_vec_3579 ,mem_vec_3580 ,mem_vec_3581 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
f372 = 0;
f372_p_0 = 0;
y = 0;
yp_0 = 0;
x352 = 0;
x352_p_0 = 0;
f = 0;
fp_1 = 0;
c372 = 0;
c372_p_0 = 0;
						for (w = w215, wp_0 = 0;w < w215 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x352, xp_1 = x352_p_0, xp_0 = 0;x < x352 + 14;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3544 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_3545 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_3546 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_3547 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_3548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_3549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_3550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_3551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_3552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_3553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_3554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_3555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_3556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_3557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_3558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_3559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_3560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_3561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c372, cp_1 = c372_p_0, cp_0 = 0;c < c372 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3544);
											mem_vec_3544 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3545);
											mem_vec_3545 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3546);
											mem_vec_3546 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3547);
											mem_vec_3547 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3548);
											mem_vec_3548 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3549);
											mem_vec_3549 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3550);
											mem_vec_3550 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3551);
											mem_vec_3551 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3552);
											mem_vec_3552 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3553);
											mem_vec_3553 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3554);
											mem_vec_3554 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3555);
											mem_vec_3555 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3556);
											mem_vec_3556 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3557);
											mem_vec_3557 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3558);
											mem_vec_3558 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3559);
											mem_vec_3559 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3560);
											mem_vec_3560 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3561);
											mem_vec_3561 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_3544);
											mem_vec_3544 = vec_29;
											vec_33 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_3545);
											mem_vec_3545 = vec_32;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_3546);
											mem_vec_3546 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_3547);
											mem_vec_3547 = vec_36;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_3548);
											mem_vec_3548 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_3549);
											mem_vec_3549 = vec_39;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_3550);
											mem_vec_3550 = vec_40;
											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_3551);
											mem_vec_3551 = vec_42;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_3552);
											mem_vec_3552 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_3553);
											mem_vec_3553 = vec_45;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_3554);
											mem_vec_3554 = vec_46;
											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_3555);
											mem_vec_3555 = vec_48;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_3556);
											mem_vec_3556 = vec_49;
											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_3557);
											mem_vec_3557 = vec_51;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_3558);
											mem_vec_3558 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_3559);
											mem_vec_3559 = vec_54;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_3560);
											mem_vec_3560 = vec_55;
											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_3561);
											mem_vec_3561 = vec_57;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_3544);
											mem_vec_3544 = vec_58;
											vec_62 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_3545);
											mem_vec_3545 = vec_61;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_3546);
											mem_vec_3546 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_3547);
											mem_vec_3547 = vec_65;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_3548);
											mem_vec_3548 = vec_66;
											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_3549);
											mem_vec_3549 = vec_68;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_3550);
											mem_vec_3550 = vec_69;
											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_3551);
											mem_vec_3551 = vec_71;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_3552);
											mem_vec_3552 = vec_72;
											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_3553);
											mem_vec_3553 = vec_74;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_3554);
											mem_vec_3554 = vec_75;
											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_3555);
											mem_vec_3555 = vec_77;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_3556);
											mem_vec_3556 = vec_78;
											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_3557);
											mem_vec_3557 = vec_80;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);
											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_3558);
											mem_vec_3558 = vec_81;
											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_3559);
											mem_vec_3559 = vec_83;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_3560);
											mem_vec_3560 = vec_84;
											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_3561);
											mem_vec_3561 = vec_86;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3544);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3545);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3546);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3547);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3548);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3549);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3550);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3551);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3552);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3553);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3554);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3555);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3556);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3557);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3558);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3559);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3560);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3561);
							}
						}
}
