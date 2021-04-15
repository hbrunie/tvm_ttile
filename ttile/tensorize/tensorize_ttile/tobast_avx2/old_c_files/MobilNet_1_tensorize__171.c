
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (1, c); Hoist_vars [c]; T (8, x);
  T (3, h); T (7, x); T (28, y); T (32, c); T (2, x)]
*/
IND_TYPE c, cp_0, c528_p_0, cp_1, c528, h, hp_0, x, xp_0, x674_p_0, x675_p_0, xp_1, x674_p_1, xp_2, x674, x675, y, yp_0;
IND_TYPE y352 = 0;
IND_TYPE x676 = 0;
IND_TYPE h202 = 0;
IND_TYPE w = 0;
IND_TYPE c529 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3608 ,mem_vec_3609 ,mem_vec_3610 ,mem_vec_3611 ,mem_vec_3612 ,mem_vec_3613 ,mem_vec_3614 ,mem_vec_3615 ,mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,mem_vec_3620 ,mem_vec_3621 ,mem_vec_3622 ,mem_vec_3623 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
x675 = 0;
x675_p_0 = 0;
c528 = 0;
c528_p_0 = 0;
y = 0;
yp_0 = 0;
x674 = 0;
x674_p_1 = 0;
				for (h = h202, hp_0 = 0;h < h202 + 3;h += 1, hp_0 += 1){
					// y = 4, x = 8, h = 1, w = 3, c = 1, f = 32
					// T (x, 8) (8 / 1)
					for (x = x674, xp_2 = x674_p_1, xp_1 = x674_p_0, xp_0 = 0;x < x674 + 8;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3608 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_3609 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
								mem_vec_3610 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_3611 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
								mem_vec_3612 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_3613 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
								mem_vec_3614 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_3615 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
								mem_vec_3616 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_3617 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
								mem_vec_3618 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_3619 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
								mem_vec_3620 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_3621 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
								mem_vec_3622 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_3623 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 3, c = 1, f = 32
								// T (c, 1) (1 / 1)
								for (c = c528, cp_1 = c528_p_0, cp_0 = 0;c < c528 + 1;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3608);
									mem_vec_3608 = vec_0;
									vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3609);
									mem_vec_3609 = vec_3;
									vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3610);
									mem_vec_3610 = vec_5;
									vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3611);
									mem_vec_3611 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);
									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3612);
									mem_vec_3612 = vec_9;
									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3613);
									mem_vec_3613 = vec_11;
									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3614);
									mem_vec_3614 = vec_12;
									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3615);
									mem_vec_3615 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);
									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3616);
									mem_vec_3616 = vec_14;
									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3617);
									mem_vec_3617 = vec_16;
									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3618);
									mem_vec_3618 = vec_17;
									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3619);
									mem_vec_3619 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);
									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3620);
									mem_vec_3620 = vec_19;
									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3621);
									mem_vec_3621 = vec_21;
									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3622);
									mem_vec_3622 = vec_22;
									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3623);
									mem_vec_3623 = vec_23;
									scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
									vec_25 = _mm256_set1_ps(scal_4);
									vec_26 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
									vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_3608);
									mem_vec_3608 = vec_24;
									vec_28 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 8]);
									vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_3609);
									mem_vec_3609 = vec_27;
									vec_30 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
									vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_3610);
									mem_vec_3610 = vec_29;
									vec_32 = _mm256_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 24]);
									vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_3611);
									mem_vec_3611 = vec_31;
									scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
									vec_34 = _mm256_set1_ps(scal_5);
									vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_3612);
									mem_vec_3612 = vec_33;
									vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_3613);
									mem_vec_3613 = vec_35;
									vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_3614);
									mem_vec_3614 = vec_36;
									vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_3615);
									mem_vec_3615 = vec_37;
									scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
									vec_39 = _mm256_set1_ps(scal_6);
									vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_3616);
									mem_vec_3616 = vec_38;
									vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_3617);
									mem_vec_3617 = vec_40;
									vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_3618);
									mem_vec_3618 = vec_41;
									vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_3619);
									mem_vec_3619 = vec_42;
									scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
									vec_44 = _mm256_set1_ps(scal_7);
									vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_3620);
									mem_vec_3620 = vec_43;
									vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3621);
									mem_vec_3621 = vec_45;
									vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3622);
									mem_vec_3622 = vec_46;
									vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_3623);
									mem_vec_3623 = vec_47;
									scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
									vec_49 = _mm256_set1_ps(scal_8);
									vec_50 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
									vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_3608);
									mem_vec_3608 = vec_48;
									vec_52 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 8]);
									vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_3609);
									mem_vec_3609 = vec_51;
									vec_54 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
									vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_3610);
									mem_vec_3610 = vec_53;
									vec_56 = _mm256_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 24]);
									vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_3611);
									mem_vec_3611 = vec_55;
									scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
									vec_58 = _mm256_set1_ps(scal_9);
									vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_3612);
									mem_vec_3612 = vec_57;
									vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_3613);
									mem_vec_3613 = vec_59;
									vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3614);
									mem_vec_3614 = vec_60;
									vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3615);
									mem_vec_3615 = vec_61;
									scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
									vec_63 = _mm256_set1_ps(scal_10);
									vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_3616);
									mem_vec_3616 = vec_62;
									vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_3617);
									mem_vec_3617 = vec_64;
									vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_3618);
									mem_vec_3618 = vec_65;
									vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_3619);
									mem_vec_3619 = vec_66;
									scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
									vec_68 = _mm256_set1_ps(scal_11);
									vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_3620);
									mem_vec_3620 = vec_67;
									vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_3621);
									mem_vec_3621 = vec_69;
									vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_3622);
									mem_vec_3622 = vec_70;
									vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_3623);
									mem_vec_3623 = vec_71;
								}
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3608);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_3609);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3610);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_3611);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3612);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_3613);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3614);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_3615);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3616);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_3617);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3618);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_3619);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3620);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_3621);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3622);
							_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_3623);
					}
				}
}
