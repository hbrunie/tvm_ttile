void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (4, c); T (8, f); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, c)]
*/
IND_TYPE c, cp_0, c1010_p_0, c1011_p_0, cp_1, c1010_p_1, cp_2, c1010, c1011, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x774_p_0, xp_1, x774, y, yp_0;
IND_TYPE y516 = 0;
IND_TYPE x775 = 0;
IND_TYPE h414 = 0;
IND_TYPE w488 = 0;
IND_TYPE c1012 = 0;
IND_TYPE f888 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7164 ,mem_vec_7165 ,mem_vec_7166 ,mem_vec_7167 ,mem_vec_7168 ,mem_vec_7169 ,mem_vec_7170 ,mem_vec_7171 ,mem_vec_7172 ,mem_vec_7173 ,mem_vec_7174 ,mem_vec_7175 ,mem_vec_7176 ,mem_vec_7177 ,mem_vec_7178 ,mem_vec_7179 ,mem_vec_7180 ,mem_vec_7181 ,mem_vec_7182 ,mem_vec_7183 ,mem_vec_7184 ,mem_vec_7185 ,mem_vec_7186 ,mem_vec_7187 ,mem_vec_7188 ,mem_vec_7189 ,mem_vec_7190 ,mem_vec_7191 ,mem_vec_7192 ,mem_vec_7193 ,mem_vec_7194 ,mem_vec_7195 ,mem_vec_7196 ,mem_vec_7197 ,mem_vec_7198 ,mem_vec_7199 ,mem_vec_7200 ,mem_vec_7201 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (c, 8) (256 / 32)
c1011 = 0;
c1011_p_0 = 0;
y = 0;
yp_0 = 0;
x774 = 0;
x774_p_0 = 0;
f = 0;
fp_0 = 0;
c1010 = 0;
c1010_p_1 = 0;
						for (h = h414, hp_0 = 0;h < h414 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w488, wp_0 = 0;w < w488 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 8, f = 32
								// T (x, 7) (7 / 1)
								for (x = x774, xp_1 = x774_p_0, xp_0 = 0;x < x774 + 7;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7182 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_7183 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_7184 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_7185 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_7186 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_7187 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_7188 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_7189 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_7190 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_7191 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_7192 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_7193 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_7194 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_7195 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_7196 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_7197 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_7198 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_7199 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_7200 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_7201 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c1010, cp_2 = c1010_p_1, cp_1 = c1010_p_0, cp_0 = 0;c < c1010 + 8;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7182);
												mem_vec_7182 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7183);
												mem_vec_7183 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7184);
												mem_vec_7184 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7185);
												mem_vec_7185 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7186);
												mem_vec_7186 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7187);
												mem_vec_7187 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7188);
												mem_vec_7188 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7189);
												mem_vec_7189 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7190);
												mem_vec_7190 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7191);
												mem_vec_7191 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7192);
												mem_vec_7192 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7193);
												mem_vec_7193 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7194);
												mem_vec_7194 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7195);
												mem_vec_7195 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7196);
												mem_vec_7196 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7197);
												mem_vec_7197 = vec_25;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7198);
												mem_vec_7198 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7199);
												mem_vec_7199 = vec_28;
												scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7200);
												mem_vec_7200 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7201);
												mem_vec_7201 = vec_31;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7182);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7183);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7184);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7185);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7186);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7187);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7188);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7189);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7190);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7191);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7192);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7193);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7194);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_7195);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7196);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_7197);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_7198);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_7199);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_7200);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_7201);
								}
							}
						}
}
