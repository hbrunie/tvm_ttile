
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1528_p_0, c1529_p_0, cp_1, c1528_p_1, cp_2, c1528, c1529, f, fp_0, x, xp_0, x1146_p_0, xp_1, x1146, y, yp_0;
IND_TYPE y764 = 0;
IND_TYPE x1147 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1530 = 0;
IND_TYPE f764 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_13752 ,mem_vec_13753 ,mem_vec_13754 ,mem_vec_13755 ,mem_vec_13756 ,mem_vec_13757 ,mem_vec_13758 ,mem_vec_13759 ,mem_vec_13760 ,mem_vec_13761 ,mem_vec_13762 ,mem_vec_13763 ,mem_vec_13764 ,mem_vec_13765 ,mem_vec_13766 ,mem_vec_13767 ,mem_vec_13768 ,mem_vec_13769 ,mem_vec_13770 ,mem_vec_13771 ,mem_vec_13772 ,mem_vec_13773 ,mem_vec_13774 ,mem_vec_13775 ,mem_vec_13776 ,mem_vec_13777 ,mem_vec_13778 ,mem_vec_13779 ,mem_vec_13780 ,mem_vec_13781 ,mem_vec_13782 ,mem_vec_13783 ,mem_vec_13784 ,mem_vec_13785 ,mem_vec_13786 ,mem_vec_13787 ,mem_vec_13788 ,mem_vec_13789 ,mem_vec_13790 ,mem_vec_13791 ,mem_vec_13792 ,mem_vec_13793 ,mem_vec_13794 ,mem_vec_13795 ,mem_vec_13796 ,mem_vec_13797 ,mem_vec_13798 ,mem_vec_13799 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 2) (1024 / 512)
c1529 = 0;
c1529_p_0 = 0;
y = 0;
yp_0 = 0;
x1146 = 0;
x1146_p_0 = 0;
f = 0;
fp_0 = 0;
c1528 = 0;
c1528_p_1 = 0;
						for (x = x1146, xp_1 = x1146_p_0, xp_0 = 0;x < x1146 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13752 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_13753 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_13754 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_13755 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_13756 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_13757 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_13758 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_13759 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_13760 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_13761 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_13762 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_13763 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_13764 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_13765 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_13766 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_13767 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_13768 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_13769 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_13770 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_13771 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c1528, cp_2 = c1528_p_1, cp_1 = c1528_p_0, cp_0 = 0;c < c1528 + 256;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13752);
										mem_vec_13752 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13753);
										mem_vec_13753 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13754);
										mem_vec_13754 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13755);
										mem_vec_13755 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13756);
										mem_vec_13756 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13757);
										mem_vec_13757 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13758);
										mem_vec_13758 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13759);
										mem_vec_13759 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13760);
										mem_vec_13760 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13761);
										mem_vec_13761 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13762);
										mem_vec_13762 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13763);
										mem_vec_13763 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13764);
										mem_vec_13764 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13765);
										mem_vec_13765 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13766);
										mem_vec_13766 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13767);
										mem_vec_13767 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13768);
										mem_vec_13768 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13769);
										mem_vec_13769 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13770);
										mem_vec_13770 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13771);
										mem_vec_13771 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13752);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13753);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_13754);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_13755);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13756);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13757);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_13758);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_13759);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13760);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13761);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_13762);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_13763);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13764);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13765);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_13766);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_13767);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_13768);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_13769);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_13770);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_13771);
						}
}
