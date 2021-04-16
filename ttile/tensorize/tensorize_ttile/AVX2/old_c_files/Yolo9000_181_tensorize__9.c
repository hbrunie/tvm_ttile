
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (3, w);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (8, c); T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c42_p_0, cp_1, c42, f, fp_0, f56_p_0, f57_p_0, fp_1, f56_p_1, fp_2, f56, f57, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y28 = 0;
IND_TYPE x28 = 0;
IND_TYPE h = 0;
IND_TYPE w26 = 0;
IND_TYPE c43 = 0;
IND_TYPE f58 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,mem_vec_560 ,mem_vec_561 ,mem_vec_562 ,mem_vec_563 ,mem_vec_564 ,mem_vec_565 ,mem_vec_566 ,mem_vec_567 ,mem_vec_568 ,mem_vec_569 ,mem_vec_570 ,mem_vec_571 ,mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
f57 = 0;
f57_p_0 = 0;
f56 = 0;
f56_p_1 = 0;
c42 = 0;
c42_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
x = 0;
xp_0 = 0;
							for (w = w26, wp_0 = 0;w < w26 + 3;w += 1, wp_0 += 1){
										mem_vec_544 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_545 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
										mem_vec_546 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_547 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
										mem_vec_548 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_549 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
										mem_vec_550 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_551 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
										mem_vec_552 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_553 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
										mem_vec_554 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_555 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
										mem_vec_556 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_557 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
										mem_vec_558 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_559 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c42, cp_1 = c42_p_0, cp_0 = 0;c < c42 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_544);
											mem_vec_544 = vec_0;
											vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_545);
											mem_vec_545 = vec_3;
											vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_546);
											mem_vec_546 = vec_5;
											vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_547);
											mem_vec_547 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);
											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_548);
											mem_vec_548 = vec_9;
											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_549);
											mem_vec_549 = vec_11;
											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_550);
											mem_vec_550 = vec_12;
											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_551);
											mem_vec_551 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);
											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_552);
											mem_vec_552 = vec_14;
											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_553);
											mem_vec_553 = vec_16;
											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_554);
											mem_vec_554 = vec_17;
											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_555);
											mem_vec_555 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);
											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_556);
											mem_vec_556 = vec_19;
											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_557);
											mem_vec_557 = vec_21;
											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_558);
											mem_vec_558 = vec_22;
											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_559);
											mem_vec_559 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_544);
											mem_vec_544 = vec_24;
											vec_28 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 8]);
											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_545);
											mem_vec_545 = vec_27;
											vec_30 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_546);
											mem_vec_546 = vec_29;
											vec_32 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 24]);
											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_547);
											mem_vec_547 = vec_31;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_34 = _mm256_set1_ps(scal_5);
											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_548);
											mem_vec_548 = vec_33;
											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_549);
											mem_vec_549 = vec_35;
											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_550);
											mem_vec_550 = vec_36;
											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_551);
											mem_vec_551 = vec_37;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);
											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_552);
											mem_vec_552 = vec_38;
											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_553);
											mem_vec_553 = vec_40;
											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_554);
											mem_vec_554 = vec_41;
											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_555);
											mem_vec_555 = vec_42;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);
											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_556);
											mem_vec_556 = vec_43;
											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_557);
											mem_vec_557 = vec_45;
											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_558);
											mem_vec_558 = vec_46;
											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_559);
											mem_vec_559 = vec_47;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_544);
											mem_vec_544 = vec_48;
											vec_52 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 8]);
											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_545);
											mem_vec_545 = vec_51;
											vec_54 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_546);
											mem_vec_546 = vec_53;
											vec_56 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 24]);
											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_547);
											mem_vec_547 = vec_55;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_9);
											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_548);
											mem_vec_548 = vec_57;
											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_549);
											mem_vec_549 = vec_59;
											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_550);
											mem_vec_550 = vec_60;
											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_551);
											mem_vec_551 = vec_61;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_63 = _mm256_set1_ps(scal_10);
											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_552);
											mem_vec_552 = vec_62;
											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_553);
											mem_vec_553 = vec_64;
											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_554);
											mem_vec_554 = vec_65;
											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_555);
											mem_vec_555 = vec_66;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);
											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_556);
											mem_vec_556 = vec_67;
											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_557);
											mem_vec_557 = vec_69;
											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_558);
											mem_vec_558 = vec_70;
											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_559);
											mem_vec_559 = vec_71;
										}
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_544);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_545);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_546);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_547);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_548);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_549);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_550);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_551);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_552);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_553);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_554);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_555);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_556);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_557);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_558);
									_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_559);
							}
}
