void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (2, f);
  T (2, c); T (16, f)]
*/
IND_TYPE c, cp_0, c692_p_0, cp_1, c692, f, fp_0, f736_p_0, f737_p_0, fp_1, f736_p_1, fp_2, f736, f737, h, hp_0, x, xp_0, x612_p_0, xp_1, x612, y, yp_0;
IND_TYPE y408 = 0;
IND_TYPE x613 = 0;
IND_TYPE h294 = 0;
IND_TYPE w = 0;
IND_TYPE c693 = 0;
IND_TYPE f738 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,mem_vec_5400 ,mem_vec_5401 ,mem_vec_5402 ,mem_vec_5403 ,mem_vec_5404 ,mem_vec_5405 ,mem_vec_5406 ,mem_vec_5407 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
f737 = 0;
f737_p_0 = 0;
c692 = 0;
c692_p_0 = 0;
f736 = 0;
f736_p_1 = 0;
y = 0;
yp_0 = 0;
x612 = 0;
x612_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h294, hp_0 = 0;h < h294 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 32
								// T (x, 17) (17 / 1)
								for (x = x612, xp_1 = x612_p_0, xp_0 = 0;x < x612 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5396 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5397 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5398 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5399 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5400 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5401 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5402 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5403 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5404 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5405 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5406 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5407 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c692, cp_1 = c692_p_0, cp_0 = 0;c < c692 + 256;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5396);
												mem_vec_5396 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5397);
												mem_vec_5397 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5398);
												mem_vec_5398 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5399);
												mem_vec_5399 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5400);
												mem_vec_5400 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5401);
												mem_vec_5401 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5402);
												mem_vec_5402 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5403);
												mem_vec_5403 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5404);
												mem_vec_5404 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5405);
												mem_vec_5405 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5406);
												mem_vec_5406 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5407);
												mem_vec_5407 = vec_19;
												scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_22 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_5396);
												mem_vec_5396 = vec_20;
												vec_24 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_5397);
												mem_vec_5397 = vec_23;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_26 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_5398);
												mem_vec_5398 = vec_25;
												vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_5399);
												mem_vec_5399 = vec_27;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_5400);
												mem_vec_5400 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_5401);
												mem_vec_5401 = vec_30;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_5402);
												mem_vec_5402 = vec_31;
												vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_5403);
												mem_vec_5403 = vec_33;
												scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_5404);
												mem_vec_5404 = vec_34;
												vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_5405);
												mem_vec_5405 = vec_36;
												scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
												vec_38 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_5406);
												mem_vec_5406 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_5407);
												mem_vec_5407 = vec_39;
												scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_5396);
												mem_vec_5396 = vec_40;
												vec_44 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_5397);
												mem_vec_5397 = vec_43;
												scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_46 = _mm512_set1_ps(scal_13);
												vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_5398);
												mem_vec_5398 = vec_45;
												vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_5399);
												mem_vec_5399 = vec_47;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5400);
												mem_vec_5400 = vec_48;
												vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_5401);
												mem_vec_5401 = vec_50;
												scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_52 = _mm512_set1_ps(scal_15);
												vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_5402);
												mem_vec_5402 = vec_51;
												vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_5403);
												mem_vec_5403 = vec_53;
												scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_55 = _mm512_set1_ps(scal_16);
												vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_5404);
												mem_vec_5404 = vec_54;
												vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_5405);
												mem_vec_5405 = vec_56;
												scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
												vec_58 = _mm512_set1_ps(scal_17);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_5406);
												mem_vec_5406 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_5407);
												mem_vec_5407 = vec_59;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5396);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5397);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5398);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5399);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5400);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5401);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5402);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5403);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5404);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5405);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5406);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5407);
								}
							}
}
