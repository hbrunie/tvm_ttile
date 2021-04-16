
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (256, c); T (17, x); T (1, y)]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, x, xp_0, x57_p_0, xp_1, x57, y, yp_0, y57_p_0, yp_1, y57;
IND_TYPE y58 = 0;
IND_TYPE x58 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y57 = 0;
y57_p_0 = 0;
x57 = 0;
x57_p_0 = 0;
c57 = 0;
c57_p_0 = 0;
			for (f = f38, fp_0 = 0;f < f38 + 512;f += 32, fp_0 += 32){
					for (y = y57, yp_1 = y57_p_0, yp_0 = 0;y < y57 + 12;y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x = x57, xp_1 = x57_p_0, xp_0 = 0;x < x57 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_684 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_685 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_686 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_687 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_688 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_689 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_690 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_691 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_692 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_693 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_694 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_695 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_696 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_697 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_698 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_699 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c57, cp_1 = c57_p_0, cp_0 = 0;c < c57 + 4;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_684);
										mem_vec_684 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_685);
										mem_vec_685 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_686);
										mem_vec_686 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_687);
										mem_vec_687 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_688);
										mem_vec_688 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_689);
										mem_vec_689 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_690);
										mem_vec_690 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_691);
										mem_vec_691 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_692);
										mem_vec_692 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_693);
										mem_vec_693 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_694);
										mem_vec_694 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_695);
										mem_vec_695 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_696);
										mem_vec_696 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_697);
										mem_vec_697 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_698);
										mem_vec_698 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_699);
										mem_vec_699 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_684);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_685);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_686);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_687);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_688);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_689);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_690);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_691);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_692);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_693);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_694);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_695);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_696);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_697);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_698);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_699);
						}
					}
					for (y = y57 + 12, yp_1 = y57_p_0, yp_0 = 0;y < y57 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x = x57, xp_1 = x57_p_0, xp_0 = 0;x < x57 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_700 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_701 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_702 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_703 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_704 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_705 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_706 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_707 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_708 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_709 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_710 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_711 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_712 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_713 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_714 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_715 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_716 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_717 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_718 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_719 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c57, cp_1 = c57_p_0, cp_0 = 0;c < c57 + 4;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_700);
										mem_vec_700 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_701);
										mem_vec_701 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_702);
										mem_vec_702 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_703);
										mem_vec_703 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_704);
										mem_vec_704 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_705);
										mem_vec_705 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_706);
										mem_vec_706 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_707);
										mem_vec_707 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_708);
										mem_vec_708 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_709);
										mem_vec_709 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_710);
										mem_vec_710 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_711);
										mem_vec_711 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_712);
										mem_vec_712 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_713);
										mem_vec_713 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_714);
										mem_vec_714 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_715);
										mem_vec_715 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_716);
										mem_vec_716 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_717);
										mem_vec_717 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_718);
										mem_vec_718 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_719);
										mem_vec_719 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_700);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_701);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_702);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_703);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_704);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_705);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_706);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_707);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_708);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_709);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_710);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_711);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_712);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_713);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_714);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_715);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_716);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_717);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_718);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_719);
						}
					}
			}
}
