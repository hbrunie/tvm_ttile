
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (7, y); U (3, h); T (16, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (2, f); T (8, c); T (2, x); T (4, y); T (2, f)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, f84_p_0, fp_1, f84, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0;
IND_TYPE y56 = 0;
IND_TYPE x85 = 0;
IND_TYPE h = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f85 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_502 ,mem_vec_503 ,mem_vec_504 ,mem_vec_505 ,mem_vec_506 ,mem_vec_507 ,mem_vec_508 ,mem_vec_509 ,mem_vec_510 ,mem_vec_511 ,mem_vec_512 ,mem_vec_513 ,mem_vec_514 ,mem_vec_515 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f84 = 0;
f84_p_0 = 0;
y = 0;
yp_0 = 0;
x84 = 0;
x84_p_0 = 0;
c84 = 0;
c84_p_0 = 0;
f = 0;
fp_1 = 0;
					for (w = w56, wp_0 = 0;w < w56 + 3;w += 1, wp_0 += 1){
						// y = 7, x = 14, h = 3, w = 1, c = 16, f = 32
						// T (x, 14) (14 / 1)
						for (x = x84, xp_1 = x84_p_0, xp_0 = 0;x < x84 + 14;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_502 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_503 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_504 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_505 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_506 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_507 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_508 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_509 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_510 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_511 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_512 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_513 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_514 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_515 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									// y = 7, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c84, cp_1 = c84_p_0, cp_0 = 0;c < c84 + 16;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_502);
										mem_vec_502 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_503);
										mem_vec_503 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_504);
										mem_vec_504 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_505);
										mem_vec_505 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_506);
										mem_vec_506 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_507);
										mem_vec_507 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_508);
										mem_vec_508 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_509);
										mem_vec_509 = vec_13;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_510);
										mem_vec_510 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_511);
										mem_vec_511 = vec_16;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_512);
										mem_vec_512 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_513);
										mem_vec_513 = vec_19;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_514);
										mem_vec_514 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_515);
										mem_vec_515 = vec_22;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_25 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_502);
										mem_vec_502 = vec_23;
										vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
										vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_503);
										mem_vec_503 = vec_26;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_504);
										mem_vec_504 = vec_28;
										vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_505);
										mem_vec_505 = vec_30;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
										vec_32 = _mm512_set1_ps(scal_9);
										vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_506);
										mem_vec_506 = vec_31;
										vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_507);
										mem_vec_507 = vec_33;
										scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_10);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_508);
										mem_vec_508 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_509);
										mem_vec_509 = vec_36;
										scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
										vec_38 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_510);
										mem_vec_510 = vec_37;
										vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_511);
										mem_vec_511 = vec_39;
										scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_512);
										mem_vec_512 = vec_40;
										vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_513);
										mem_vec_513 = vec_42;
										scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);
										vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_514);
										mem_vec_514 = vec_43;
										vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_515);
										mem_vec_515 = vec_45;
										scal_14 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
										vec_47 = _mm512_set1_ps(scal_14);
										vec_48 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
										vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_502);
										mem_vec_502 = vec_46;
										vec_50 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
										vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_503);
										mem_vec_503 = vec_49;
										scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_15);
										vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_504);
										mem_vec_504 = vec_51;
										vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_505);
										mem_vec_505 = vec_53;
										scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
										vec_55 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_506);
										mem_vec_506 = vec_54;
										vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_507);
										mem_vec_507 = vec_56;
										scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_17);
										vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_508);
										mem_vec_508 = vec_57;
										vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_509);
										mem_vec_509 = vec_59;
										scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
										vec_61 = _mm512_set1_ps(scal_18);
										vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_510);
										mem_vec_510 = vec_60;
										vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_511);
										mem_vec_511 = vec_62;
										scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_19);
										vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_512);
										mem_vec_512 = vec_63;
										vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_513);
										mem_vec_513 = vec_65;
										scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
										vec_67 = _mm512_set1_ps(scal_20);
										vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_514);
										mem_vec_514 = vec_66;
										vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_515);
										mem_vec_515 = vec_68;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_502);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_503);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_504);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_505);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_506);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_507);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_508);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_509);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_510);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_511);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_512);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_513);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_514);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_515);
						}
					}
}
