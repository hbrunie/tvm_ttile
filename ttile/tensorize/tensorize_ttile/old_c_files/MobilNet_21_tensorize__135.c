
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (8, c); T (28, x)]
*/
IND_TYPE c, cp_0, c638_p_0, cp_1, c638, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x706_p_0, x707_p_0, xp_1, x706_p_1, xp_2, x706, x707, y, yp_0;
IND_TYPE y384 = 0;
IND_TYPE x708 = 0;
IND_TYPE h348 = 0;
IND_TYPE w360 = 0;
IND_TYPE c639 = 0;
IND_TYPE f322 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6132 ,mem_vec_6133 ,mem_vec_6134 ,mem_vec_6135 ,mem_vec_6136 ,mem_vec_6137 ,mem_vec_6138 ,mem_vec_6139 ,mem_vec_6140 ,mem_vec_6141 ,mem_vec_6142 ,mem_vec_6143 ,mem_vec_6144 ,mem_vec_6145 ,mem_vec_6146 ,mem_vec_6147 ,mem_vec_6148 ,mem_vec_6149 ,mem_vec_6150 ,mem_vec_6151 ,mem_vec_6152 ,mem_vec_6153 ,mem_vec_6154 ,mem_vec_6155 ,mem_vec_6156 ,mem_vec_6157 ,mem_vec_6158 ,mem_vec_6159 ,mem_vec_6160 ,mem_vec_6161 ,mem_vec_6162 ,mem_vec_6163 ,mem_vec_6164 ,mem_vec_6165 ,mem_vec_6166 ,mem_vec_6167 ,mem_vec_6168 ,mem_vec_6169 ,mem_vec_6170 ,mem_vec_6171 ,mem_vec_6172 ,mem_vec_6173 ,mem_vec_6174 ,mem_vec_6175 ,mem_vec_6176 ,mem_vec_6177 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 28) (56 / 2)
x707 = 0;
x707_p_0 = 0;
c638 = 0;
c638_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x706 = 0;
x706_p_1 = 0;
						for (h = h348, hp_0 = 0;h < h348 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w360, wp_0 = 0;w < w360 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 8, f = 32
								// T (x, 2) (2 / 1)
								for (x = x706, xp_2 = x706_p_1, xp_1 = x706_p_0, xp_0 = 0;x < x706 + 2;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6132 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6133 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6134 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6135 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6136 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6137 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6138 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_6139 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_6140 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_6141 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_6142 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_6143 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_6144 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_6145 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_6146 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_6147 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_6148 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_6149 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_6150 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_6151 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_6152 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_6153 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c638, cp_1 = c638_p_0, cp_0 = 0;c < c638 + 8;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6132);
												mem_vec_6132 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6133);
												mem_vec_6133 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6134);
												mem_vec_6134 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6135);
												mem_vec_6135 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6136);
												mem_vec_6136 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6137);
												mem_vec_6137 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6138);
												mem_vec_6138 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6139);
												mem_vec_6139 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6140);
												mem_vec_6140 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6141);
												mem_vec_6141 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6142);
												mem_vec_6142 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6143);
												mem_vec_6143 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6144);
												mem_vec_6144 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6145);
												mem_vec_6145 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6146);
												mem_vec_6146 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6147);
												mem_vec_6147 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6148);
												mem_vec_6148 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6149);
												mem_vec_6149 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6150);
												mem_vec_6150 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6151);
												mem_vec_6151 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6152);
												mem_vec_6152 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6153);
												mem_vec_6153 = vec_34;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6132);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6133);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6134);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6135);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6136);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6137);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6138);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6139);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6140);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6141);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6142);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6143);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6144);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6145);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6146);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6147);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6148);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6149);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6150);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6151);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_6152);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_6153);
								}
							}
						}
}
