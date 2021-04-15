
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, h); Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))];
  T (1, f); T (8, c); T (1, f); T (34, x); T (8, f)]
*/
IND_TYPE c, cp_0, c540_p_0, cp_1, c540, f, fp_0, f692_p_0, f693_p_0, fp_1, f692_p_1, fp_2, f692, f693, h, hp_0, x, xp_0, x572_p_0, xp_1, x572, y, yp_0;
IND_TYPE y360 = 0;
IND_TYPE x573 = 0;
IND_TYPE h296 = 0;
IND_TYPE w = 0;
IND_TYPE c541 = 0;
IND_TYPE f694 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,mem_vec_5364 ,mem_vec_5365 ,mem_vec_5366 ,mem_vec_5367 ,mem_vec_5368 ,mem_vec_5369 ,mem_vec_5370 ,mem_vec_5371 ,mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
f693 = 0;
f693_p_0 = 0;
x572 = 0;
x572_p_0 = 0;
f692 = 0;
f692_p_1 = 0;
c540 = 0;
c540_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h296, hp_0 = 0;h < h296 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x572, xp_1 = x572_p_0, xp_0 = 0;x < x572 + 2;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5352 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5353 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5354 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5355 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5356 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5357 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5358 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5359 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5360 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5361 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5362 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5363 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_5364 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5365 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c540, cp_1 = c540_p_0, cp_0 = 0;c < c540 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5352);
												mem_vec_5352 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5353);
												mem_vec_5353 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5354);
												mem_vec_5354 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5355);
												mem_vec_5355 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5356);
												mem_vec_5356 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5357);
												mem_vec_5357 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5358);
												mem_vec_5358 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5359);
												mem_vec_5359 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5360);
												mem_vec_5360 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5361);
												mem_vec_5361 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5362);
												mem_vec_5362 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5363);
												mem_vec_5363 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5364);
												mem_vec_5364 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5365);
												mem_vec_5365 = vec_22;
												scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_5352);
												mem_vec_5352 = vec_23;
												vec_27 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
												vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_5353);
												mem_vec_5353 = vec_26;
												scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_5354);
												mem_vec_5354 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_5355);
												mem_vec_5355 = vec_30;
												scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_5356);
												mem_vec_5356 = vec_31;
												vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_5357);
												mem_vec_5357 = vec_33;
												scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_5358);
												mem_vec_5358 = vec_34;
												vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_5359);
												mem_vec_5359 = vec_36;
												scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
												vec_38 = _mm512_set1_ps(scal_11);
												vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_5360);
												mem_vec_5360 = vec_37;
												vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_5361);
												mem_vec_5361 = vec_39;
												scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_5362);
												mem_vec_5362 = vec_40;
												vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_5363);
												mem_vec_5363 = vec_42;
												scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
												vec_44 = _mm512_set1_ps(scal_13);
												vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_5364);
												mem_vec_5364 = vec_43;
												vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_5365);
												mem_vec_5365 = vec_45;
												scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
												vec_47 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
												vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_5352);
												mem_vec_5352 = vec_46;
												vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
												vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_5353);
												mem_vec_5353 = vec_49;
												scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
												vec_52 = _mm512_set1_ps(scal_15);
												vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_5354);
												mem_vec_5354 = vec_51;
												vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_5355);
												mem_vec_5355 = vec_53;
												scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
												vec_55 = _mm512_set1_ps(scal_16);
												vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_5356);
												mem_vec_5356 = vec_54;
												vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_5357);
												mem_vec_5357 = vec_56;
												scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
												vec_58 = _mm512_set1_ps(scal_17);
												vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_5358);
												mem_vec_5358 = vec_57;
												vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5359);
												mem_vec_5359 = vec_59;
												scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
												vec_61 = _mm512_set1_ps(scal_18);
												vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_5360);
												mem_vec_5360 = vec_60;
												vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_5361);
												mem_vec_5361 = vec_62;
												scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_19);
												vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_5362);
												mem_vec_5362 = vec_63;
												vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_5363);
												mem_vec_5363 = vec_65;
												scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
												vec_67 = _mm512_set1_ps(scal_20);
												vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_5364);
												mem_vec_5364 = vec_66;
												vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_5365);
												mem_vec_5365 = vec_68;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5352);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5353);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5354);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5355);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5356);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5357);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5358);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5359);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5360);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5361);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5362);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5363);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5364);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5365);
								}
							}
}
