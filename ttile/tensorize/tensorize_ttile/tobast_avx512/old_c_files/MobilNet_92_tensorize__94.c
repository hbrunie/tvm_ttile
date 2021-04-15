void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (16, c); T (16, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (4, c);
  T (1, f); T (8, c)]
*/
IND_TYPE c, cp_0, c1638_p_0, c1639_p_0, c1640_p_0, cp_1, c1638_p_1, c1639_p_1, cp_2, c1638_p_2, cp_3, c1638, c1639, c1640, f, fp_0, f1098_p_0, fp_1, f1098, h, hp_0, x, xp_0, y, yp_0;
IND_TYPE y538 = 0;
IND_TYPE x684 = 0;
IND_TYPE h502 = 0;
IND_TYPE w = 0;
IND_TYPE c1641 = 0;
IND_TYPE f1099 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_6420 ,mem_vec_6421 ,mem_vec_6422 ,mem_vec_6423 ,mem_vec_6424 ,mem_vec_6425 ,mem_vec_6426 ,mem_vec_6427 ,mem_vec_6428 ,mem_vec_6429 ,mem_vec_6430 ,mem_vec_6431 ,mem_vec_6432 ,mem_vec_6433 ,mem_vec_6434 ,mem_vec_6435 ,mem_vec_6436 ,mem_vec_6437 ,mem_vec_6438 ,mem_vec_6439 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
c1640 = 0;
c1640_p_0 = 0;
f1098 = 0;
f1098_p_0 = 0;
c1639 = 0;
c1639_p_1 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_1 = 0;
c1638 = 0;
c1638_p_2 = 0;
							for (h = h502, hp_0 = 0;h < h502 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
								// T (x, 7) (7 / 1)
								for (x = x684, xp_0 = 0;x < x684 + 7;x += 1, xp_0 += 1){
											mem_vec_6428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_6429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_6430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_6431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_6432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_6433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_6434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_6435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_6436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_6437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_6438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_6439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
											// T (c, 2) (2 / 1)
											for (c = c1638, cp_3 = c1638_p_2, cp_2 = c1638_p_1, cp_1 = c1638_p_0, cp_0 = 0;c < c1638 + 2;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6428);
												mem_vec_6428 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6429);
												mem_vec_6429 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6430);
												mem_vec_6430 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6431);
												mem_vec_6431 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6432);
												mem_vec_6432 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6433);
												mem_vec_6433 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6434);
												mem_vec_6434 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6435);
												mem_vec_6435 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6436);
												mem_vec_6436 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6437);
												mem_vec_6437 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6438);
												mem_vec_6438 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6439);
												mem_vec_6439 = vec_18;
												scal_3 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_6428);
												mem_vec_6428 = vec_19;
												vec_23 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_6429);
												mem_vec_6429 = vec_22;
												vec_25 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_6430);
												mem_vec_6430 = vec_24;
												vec_27 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_6431);
												mem_vec_6431 = vec_26;
												scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6432);
												mem_vec_6432 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_6433);
												mem_vec_6433 = vec_30;
												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6434);
												mem_vec_6434 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6435);
												mem_vec_6435 = vec_32;
												scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_6436);
												mem_vec_6436 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_6437);
												mem_vec_6437 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_6438);
												mem_vec_6438 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_6439);
												mem_vec_6439 = vec_37;
												scal_6 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_6428);
												mem_vec_6428 = vec_38;
												vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_6429);
												mem_vec_6429 = vec_41;
												vec_44 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_6430);
												mem_vec_6430 = vec_43;
												vec_46 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_6431);
												mem_vec_6431 = vec_45;
												scal_7 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_48 = _mm512_set1_ps(scal_7);
												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_6432);
												mem_vec_6432 = vec_47;
												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_6433);
												mem_vec_6433 = vec_49;
												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_6434);
												mem_vec_6434 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_6435);
												mem_vec_6435 = vec_51;
												scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_53 = _mm512_set1_ps(scal_8);
												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_6436);
												mem_vec_6436 = vec_52;
												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_6437);
												mem_vec_6437 = vec_54;
												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_6438);
												mem_vec_6438 = vec_55;
												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6439);
												mem_vec_6439 = vec_56;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6428);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6429);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_6430);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_6431);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6432);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6433);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_6434);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_6435);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6436);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6437);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_6438);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_6439);
								}
							}
}
