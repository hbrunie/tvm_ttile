
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, f); T (8, c); T (28, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (2, f)]
*/
IND_TYPE c, cp_0, c666_p_0, cp_1, c666, f, fp_0, f738_p_0, fp_1, f738, h, hp_0, w, wp_0, x, xp_0, x666_p_0, xp_1, x666, y, yp_0;
IND_TYPE y444 = 0;
IND_TYPE x667 = 0;
IND_TYPE h370 = 0;
IND_TYPE w394 = 0;
IND_TYPE c667 = 0;
IND_TYPE f739 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5636 ,mem_vec_5637 ,mem_vec_5638 ,mem_vec_5639 ,mem_vec_5640 ,mem_vec_5641 ,mem_vec_5642 ,mem_vec_5643 ,mem_vec_5644 ,mem_vec_5645 ,mem_vec_5646 ,mem_vec_5647 ,mem_vec_5648 ,mem_vec_5649 ,mem_vec_5650 ,mem_vec_5651 ,mem_vec_5652 ,mem_vec_5653 ,mem_vec_5654 ,mem_vec_5655 ,mem_vec_5656 ,mem_vec_5657 ,mem_vec_5658 ,mem_vec_5659 ,mem_vec_5660 ,mem_vec_5661 ,mem_vec_5662 ,mem_vec_5663 ,mem_vec_5664 ,mem_vec_5665 ,mem_vec_5666 ,mem_vec_5667 ,mem_vec_5668 ,mem_vec_5669 ,mem_vec_5670 ,mem_vec_5671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f738 = 0;
f738_p_0 = 0;
y = 0;
yp_0 = 0;
x666 = 0;
x666_p_0 = 0;
c666 = 0;
c666_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h370, hp_0 = 0;h < h370 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w394, wp_0 = 0;w < w394 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x666, xp_1 = x666_p_0, xp_0 = 0;x < x666 + 1;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5636 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_5637 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_5638 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_5639 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_5640 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_5641 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_5642 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_5643 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_5644 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_5645 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_5646 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_5647 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_5648 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_5649 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_5650 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_5651 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c666, cp_1 = c666_p_0, cp_0 = 0;c < c666 + 16;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5636);
												mem_vec_5636 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5637);
												mem_vec_5637 = vec_3;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5638);
												mem_vec_5638 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5639);
												mem_vec_5639 = vec_7;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5640);
												mem_vec_5640 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5641);
												mem_vec_5641 = vec_10;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5642);
												mem_vec_5642 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5643);
												mem_vec_5643 = vec_13;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5644);
												mem_vec_5644 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5645);
												mem_vec_5645 = vec_16;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5646);
												mem_vec_5646 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5647);
												mem_vec_5647 = vec_19;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5648);
												mem_vec_5648 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5649);
												mem_vec_5649 = vec_22;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5650);
												mem_vec_5650 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5651);
												mem_vec_5651 = vec_25;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5636);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5637);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5638);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5639);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5640);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5641);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5642);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5643);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5644);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5645);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5646);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5647);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5648);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5649);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5650);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5651);
								}
							}
						}
}
