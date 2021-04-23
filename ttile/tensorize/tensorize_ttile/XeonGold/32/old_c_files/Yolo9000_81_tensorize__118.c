
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (4, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c366_p_0, cp_1, c366, f, fp_0, f482_p_0, f483_p_0, fp_1, f482_p_1, fp_2, f482, f483, h, hp_0, w, wp_0, x, xp_0, x366_p_0, xp_1, x366, y, yp_0;
IND_TYPE y247 = 0;
IND_TYPE x367 = 0;
IND_TYPE h241 = 0;
IND_TYPE w221 = 0;
IND_TYPE c367 = 0;
IND_TYPE f484 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4636 ,mem_vec_4637 ,mem_vec_4638 ,mem_vec_4639 ,mem_vec_4640 ,mem_vec_4641 ,mem_vec_4642 ,mem_vec_4643 ,mem_vec_4644 ,mem_vec_4645 ,mem_vec_4646 ,mem_vec_4647 ,mem_vec_4648 ,mem_vec_4649 ,mem_vec_4650 ,mem_vec_4651 ,mem_vec_4652 ,mem_vec_4653 ,mem_vec_4654 ,mem_vec_4655 ,mem_vec_4656 ,mem_vec_4657 ,mem_vec_4658 ,mem_vec_4659 ,mem_vec_4660 ,mem_vec_4661 ,mem_vec_4662 ,mem_vec_4663 ,mem_vec_4664 ,mem_vec_4665 ,mem_vec_4666 ,mem_vec_4667 ,mem_vec_4668 ,mem_vec_4669 ,mem_vec_4670 ,mem_vec_4671 ,mem_vec_4672 ,mem_vec_4673 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f483 = 0;
f483_p_0 = 0;
f482 = 0;
f482_p_1 = 0;
x366 = 0;
x366_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c366 = 0;
c366_p_0 = 0;
							for (w = w221, wp_0 = 0;w < w221 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x366, xp_1 = x366_p_0, xp_0 = 0;x < x366 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h241, hp_0 = 0;h < h241 + 3;h += 1, hp_0 += 1){
												mem_vec_4636 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4637 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4638 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_4639 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_4640 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_4641 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_4642 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_4643 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_4644 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_4645 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_4646 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_4647 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_4648 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_4649 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_4650 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_4651 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c366, cp_1 = c366_p_0, cp_0 = 0;c < c366 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4636);
													mem_vec_4636 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4637);
													mem_vec_4637 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4638);
													mem_vec_4638 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4639);
													mem_vec_4639 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4640);
													mem_vec_4640 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4641);
													mem_vec_4641 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4642);
													mem_vec_4642 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4643);
													mem_vec_4643 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4644);
													mem_vec_4644 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4645);
													mem_vec_4645 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4646);
													mem_vec_4646 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4647);
													mem_vec_4647 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4648);
													mem_vec_4648 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4649);
													mem_vec_4649 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4650);
													mem_vec_4650 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4651);
													mem_vec_4651 = vec_25;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4636);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4637);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4638);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4639);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4640);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4641);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4642);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4643);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4644);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4645);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4646);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4647);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4648);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4649);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4650);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4651);
									}
								}
							}
}
