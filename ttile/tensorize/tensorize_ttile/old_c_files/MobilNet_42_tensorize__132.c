void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (2, f); T (8, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (2, f)]
*/
IND_TYPE c, cp_0, c654_p_0, cp_1, c654, f, fp_0, f654_p_0, fp_1, f654, h, hp_0, w, wp_0, x, xp_0, x654_p_0, xp_1, x654, y, yp_0;
IND_TYPE y436 = 0;
IND_TYPE x655 = 0;
IND_TYPE h368 = 0;
IND_TYPE w406 = 0;
IND_TYPE c655 = 0;
IND_TYPE f655 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6112 ,mem_vec_6113 ,mem_vec_6114 ,mem_vec_6115 ,mem_vec_6116 ,mem_vec_6117 ,mem_vec_6118 ,mem_vec_6119 ,mem_vec_6120 ,mem_vec_6121 ,mem_vec_6122 ,mem_vec_6123 ,mem_vec_6124 ,mem_vec_6125 ,mem_vec_6126 ,mem_vec_6127 ,mem_vec_6128 ,mem_vec_6129 ,mem_vec_6130 ,mem_vec_6131 ,mem_vec_6132 ,mem_vec_6133 ,mem_vec_6134 ,mem_vec_6135 ,mem_vec_6136 ,mem_vec_6137 ,mem_vec_6138 ,mem_vec_6139 ,mem_vec_6140 ,mem_vec_6141 ,mem_vec_6142 ,mem_vec_6143 ,mem_vec_6144 ,mem_vec_6145 ,mem_vec_6146 ,mem_vec_6147 ,mem_vec_6148 ,mem_vec_6149 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f654 = 0;
f654_p_0 = 0;
y = 0;
yp_0 = 0;
x654 = 0;
x654_p_0 = 0;
c654 = 0;
c654_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h368, hp_0 = 0;h < h368 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w406, wp_0 = 0;w < w406 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 16, f = 32
								// T (x, 28) (28 / 1)
								for (x = x654, xp_1 = x654_p_0, xp_0 = 0;x < x654 + 28;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6130 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6131 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6132 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6133 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6134 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6135 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6136 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6137 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6138 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6139 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6140 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6141 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6142 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_6143 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_6144 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_6145 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_6146 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_6147 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_6148 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_6149 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c654, cp_1 = c654_p_0, cp_0 = 0;c < c654 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6130);
												mem_vec_6130 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6131);
												mem_vec_6131 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6132);
												mem_vec_6132 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6133);
												mem_vec_6133 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6134);
												mem_vec_6134 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6135);
												mem_vec_6135 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6136);
												mem_vec_6136 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6137);
												mem_vec_6137 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6138);
												mem_vec_6138 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6139);
												mem_vec_6139 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6140);
												mem_vec_6140 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6141);
												mem_vec_6141 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6142);
												mem_vec_6142 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6143);
												mem_vec_6143 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6144);
												mem_vec_6144 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6145);
												mem_vec_6145 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6146);
												mem_vec_6146 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6147);
												mem_vec_6147 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6148);
												mem_vec_6148 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6149);
												mem_vec_6149 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6130);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6131);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6132);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6133);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6134);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6135);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6136);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6137);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6138);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6139);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6140);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6141);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6142);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6143);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6144);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6145);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6146);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6147);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6148);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6149);
								}
							}
						}
}
