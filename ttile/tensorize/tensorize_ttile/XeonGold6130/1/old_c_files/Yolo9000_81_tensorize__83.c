
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (2, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, f64_p_0, f65_p_0, fp_1, f64_p_1, fp_2, f64, f65, h, hp_0, w, wp_0, x, xp_0, x48_p_0, xp_1, x48, y, yp_0;
IND_TYPE y32 = 0;
IND_TYPE x49 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c49 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f65 = 0;
f65_p_0 = 0;
f64 = 0;
f64_p_1 = 0;
x48 = 0;
x48_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c48 = 0;
c48_p_0 = 0;
							for (w = w32, wp_0 = 0;w < w32 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x48, xp_1 = x48_p_0, xp_0 = 0;x < x48 + 34;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h32, hp_0 = 0;h < h32 + 3;h += 1, hp_0 += 1){
												mem_vec_620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c48, cp_1 = c48_p_0, cp_0 = 0;c < c48 + 16;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_620);
													mem_vec_620 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_621);
													mem_vec_621 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_622);
													mem_vec_622 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_623);
													mem_vec_623 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_624);
													mem_vec_624 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_625);
													mem_vec_625 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_626);
													mem_vec_626 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_627);
													mem_vec_627 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_628);
													mem_vec_628 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_629);
													mem_vec_629 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_630);
													mem_vec_630 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_631);
													mem_vec_631 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_632);
													mem_vec_632 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_633);
													mem_vec_633 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_634);
													mem_vec_634 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_635);
													mem_vec_635 = vec_25;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_620);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_621);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_622);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_623);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_624);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_625);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_626);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_627);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_628);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_629);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_630);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_631);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_632);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_633);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_634);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_635);
									}
								}
							}
}
