
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (8, f); U (2, y); U (3, w); T (128, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (17, y); T (1, x); T (4, f); T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c65_p_0, c66_p_0, cp_1, c65_p_1, cp_2, c65, c66, f, fp_0, f63_p_0, fp_1, f63, h, hp_0, x, xp_0, x62_p_0, xp_1, x62, y, yp_0;
IND_TYPE y46 = 0;
IND_TYPE x63 = 0;
IND_TYPE h38 = 0;
IND_TYPE w = 0;
IND_TYPE c67 = 0;
IND_TYPE f64 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_350 ,mem_vec_351 ,mem_vec_352 ,mem_vec_353 ,mem_vec_354 ,mem_vec_355 ,mem_vec_356 ,mem_vec_357 ,mem_vec_358 ,mem_vec_359 ,mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f63 = 0;
f63_p_0 = 0;
c66 = 0;
c66_p_0 = 0;
f = 0;
fp_1 = 0;
x62 = 0;
x62_p_0 = 0;
y = 0;
yp_0 = 0;
c65 = 0;
c65_p_1 = 0;
						for (h = h38, hp_0 = 0;h < h38 + 3;h += 1, hp_0 += 1){
							// y = 2, x = 34, h = 1, w = 3, c = 128, f = 128
							// T (x, 34) (34 / 1)
							for (x = x62, xp_1 = x62_p_0, xp_0 = 0;x < x62 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_350 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_351 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_352 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_353 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_354 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 64]);
										mem_vec_355 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 80]);
										mem_vec_356 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 96]);
										mem_vec_357 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 112]);
										mem_vec_358 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_359 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_360 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_361 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_362 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64]);
										mem_vec_363 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80]);
										mem_vec_364 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96]);
										mem_vec_365 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112]);
										// y = 2, x = 1, h = 1, w = 3, c = 128, f = 128
										// T (c, 128) (128 / 1)
										for (c = c65, cp_2 = c65_p_1, cp_1 = c65_p_0, cp_0 = 0;c < c65 + 128;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_350);
											mem_vec_350 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_351);
											mem_vec_351 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_352);
											mem_vec_352 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_353);
											mem_vec_353 = vec_7;
											vec_10 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 64]);
											vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_354);
											mem_vec_354 = vec_9;
											vec_12 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 80]);
											vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_355);
											mem_vec_355 = vec_11;
											vec_14 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 96]);
											vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_356);
											mem_vec_356 = vec_13;
											vec_16 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 112]);
											vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_357);
											mem_vec_357 = vec_15;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_18 = _mm512_set1_ps(scal_1);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_358);
											mem_vec_358 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_359);
											mem_vec_359 = vec_19;
											vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_360);
											mem_vec_360 = vec_20;
											vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_361);
											mem_vec_361 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_362);
											mem_vec_362 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_363);
											mem_vec_363 = vec_23;
											vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_364);
											mem_vec_364 = vec_24;
											vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_365);
											mem_vec_365 = vec_25;
											scal_2 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_2);
											vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_350);
											mem_vec_350 = vec_26;
											vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_351);
											mem_vec_351 = vec_29;
											vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_352);
											mem_vec_352 = vec_31;
											vec_34 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_353);
											mem_vec_353 = vec_33;
											vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 64]);
											vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_354);
											mem_vec_354 = vec_35;
											vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 80]);
											vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_355);
											mem_vec_355 = vec_37;
											vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 96]);
											vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_356);
											mem_vec_356 = vec_39;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 112]);
											vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_357);
											mem_vec_357 = vec_41;
											scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_3);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_358);
											mem_vec_358 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_359);
											mem_vec_359 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_360);
											mem_vec_360 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_361);
											mem_vec_361 = vec_47;
											vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_362);
											mem_vec_362 = vec_48;
											vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_363);
											mem_vec_363 = vec_49;
											vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_364);
											mem_vec_364 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_365);
											mem_vec_365 = vec_51;
											scal_4 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_53 = _mm512_set1_ps(scal_4);
											vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_350);
											mem_vec_350 = vec_52;
											vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_351);
											mem_vec_351 = vec_55;
											vec_58 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_352);
											mem_vec_352 = vec_57;
											vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_353);
											mem_vec_353 = vec_59;
											vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 64]);
											vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_354);
											mem_vec_354 = vec_61;
											vec_64 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 80]);
											vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_355);
											mem_vec_355 = vec_63;
											vec_66 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 96]);
											vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_356);
											mem_vec_356 = vec_65;
											vec_68 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 112]);
											vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_357);
											mem_vec_357 = vec_67;
											scal_5 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_70 = _mm512_set1_ps(scal_5);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_358);
											mem_vec_358 = vec_69;
											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_359);
											mem_vec_359 = vec_71;
											vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_360);
											mem_vec_360 = vec_72;
											vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_361);
											mem_vec_361 = vec_73;
											vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_362);
											mem_vec_362 = vec_74;
											vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_363);
											mem_vec_363 = vec_75;
											vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_364);
											mem_vec_364 = vec_76;
											vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_365);
											mem_vec_365 = vec_77;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_350);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_351);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_352);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_353);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 64], mem_vec_354);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 80], mem_vec_355);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 96], mem_vec_356);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 112], mem_vec_357);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_358);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_359);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_360);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_361);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 64], mem_vec_362);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 80], mem_vec_363);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 96], mem_vec_364);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 112], mem_vec_365);
							}
						}
}
