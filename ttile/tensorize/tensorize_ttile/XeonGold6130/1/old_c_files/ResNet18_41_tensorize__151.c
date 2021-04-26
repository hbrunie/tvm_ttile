
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (1, c); T (4, f); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (1, f)]
*/
IND_TYPE c, cp_0, c528_p_0, cp_1, c528, f, fp_0, f528_p_0, fp_1, f528, h, hp_0, w, wp_0, x, xp_0, x510_p_0, xp_1, x510, y, yp_0;
IND_TYPE y352 = 0;
IND_TYPE x511 = 0;
IND_TYPE h314 = 0;
IND_TYPE w332 = 0;
IND_TYPE c529 = 0;
IND_TYPE f529 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6002 ,mem_vec_6003 ,mem_vec_6004 ,mem_vec_6005 ,mem_vec_6006 ,mem_vec_6007 ,mem_vec_6008 ,mem_vec_6009 ,mem_vec_6010 ,mem_vec_6011 ,mem_vec_6012 ,mem_vec_6013 ,mem_vec_6014 ,mem_vec_6015 ,mem_vec_6016 ,mem_vec_6017 ,mem_vec_6018 ,mem_vec_6019 ,mem_vec_6020 ,mem_vec_6021 ,mem_vec_6022 ,mem_vec_6023 ,mem_vec_6024 ,mem_vec_6025 ,mem_vec_6026 ,mem_vec_6027 ,mem_vec_6028 ,mem_vec_6029 ,mem_vec_6030 ,mem_vec_6031 ,mem_vec_6032 ,mem_vec_6033 ,mem_vec_6034 ,mem_vec_6035 ,mem_vec_6036 ,mem_vec_6037 ,mem_vec_6038 ,mem_vec_6039 ,mem_vec_6040 ,mem_vec_6041 ,mem_vec_6042 ,mem_vec_6043 ,mem_vec_6044 ,mem_vec_6045 ,mem_vec_6046 ,mem_vec_6047 ,mem_vec_6048 ,mem_vec_6049 ,mem_vec_6050 ,mem_vec_6051 ,mem_vec_6052 ,mem_vec_6053 ,mem_vec_6054 ,mem_vec_6055 ,mem_vec_6056 ,mem_vec_6057 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
f528 = 0;
f528_p_0 = 0;
y = 0;
yp_0 = 0;
x510 = 0;
x510_p_0 = 0;
f = 0;
fp_1 = 0;
c528 = 0;
c528_p_0 = 0;
						for (w = w332, wp_0 = 0;w < w332 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 32
							// T (x, 7) (7 / 1)
							for (x = x510, xp_1 = x510_p_0, xp_0 = 0;x < x510 + 7;x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
								// T (h, 3) (3 / 1)
								for (h = h314, hp_0 = 0;h < h314 + 3;h += 1, hp_0 += 1){
											mem_vec_6002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_6015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_6016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_6017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_6018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_6019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_6020 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_6021 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_6022 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_6023 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_6024 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_6025 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_6026 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_6027 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c528, cp_1 = c528_p_0, cp_0 = 0;c < c528 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6002);
												mem_vec_6002 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6003);
												mem_vec_6003 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6004);
												mem_vec_6004 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6005);
												mem_vec_6005 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6006);
												mem_vec_6006 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6007);
												mem_vec_6007 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6008);
												mem_vec_6008 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6009);
												mem_vec_6009 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6010);
												mem_vec_6010 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6011);
												mem_vec_6011 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6012);
												mem_vec_6012 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6013);
												mem_vec_6013 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6014);
												mem_vec_6014 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6015);
												mem_vec_6015 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6016);
												mem_vec_6016 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6017);
												mem_vec_6017 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6018);
												mem_vec_6018 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6019);
												mem_vec_6019 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6020);
												mem_vec_6020 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6021);
												mem_vec_6021 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6022);
												mem_vec_6022 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6023);
												mem_vec_6023 = vec_34;
												scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6024);
												mem_vec_6024 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6025);
												mem_vec_6025 = vec_37;
												scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6026);
												mem_vec_6026 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6027);
												mem_vec_6027 = vec_40;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6002);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6003);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6004);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6005);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6006);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6007);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6008);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6009);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6010);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6011);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6012);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6013);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6014);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6015);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6016);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6017);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6018);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6019);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6020);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6021);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_6022);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_6023);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_6024);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_6025);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_6026);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_6027);
								}
							}
						}
}
