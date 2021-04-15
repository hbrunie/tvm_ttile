
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (2, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1122_p_0, cp_1, c1122, f, fp_0, x, xp_0, x1496_p_0, x1497_p_0, xp_1, x1496_p_1, xp_2, x1496, x1497, y, yp_0;
IND_TYPE y748 = 0;
IND_TYPE x1498 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1123 = 0;
IND_TYPE f748 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15728 ,mem_vec_15729 ,mem_vec_15730 ,mem_vec_15731 ,mem_vec_15732 ,mem_vec_15733 ,mem_vec_15734 ,mem_vec_15735 ,mem_vec_15736 ,mem_vec_15737 ,mem_vec_15738 ,mem_vec_15739 ,mem_vec_15740 ,mem_vec_15741 ,mem_vec_15742 ,mem_vec_15743 ,mem_vec_15744 ,mem_vec_15745 ,mem_vec_15746 ,mem_vec_15747 ,mem_vec_15748 ,mem_vec_15749 ,mem_vec_15750 ,mem_vec_15751 ,mem_vec_15752 ,mem_vec_15753 ,mem_vec_15754 ,mem_vec_15755 ,mem_vec_15756 ,mem_vec_15757 ,mem_vec_15758 ,mem_vec_15759 ,mem_vec_15760 ,mem_vec_15761 ,mem_vec_15762 ,mem_vec_15763 ,mem_vec_15764 ,mem_vec_15765 ,mem_vec_15766 ,mem_vec_15767 ,mem_vec_15768 ,mem_vec_15769 ,mem_vec_15770 ,mem_vec_15771 ,mem_vec_15772 ,mem_vec_15773 ,mem_vec_15774 ,mem_vec_15775 ,mem_vec_15776 ,mem_vec_15777 ,mem_vec_15778 ,mem_vec_15779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
x1497 = 0;
x1497_p_0 = 0;
c1122 = 0;
c1122_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1496 = 0;
x1496_p_1 = 0;
						for (x = x1496, xp_2 = x1496_p_1, xp_1 = x1496_p_0, xp_0 = 0;x < x1496 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15728 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_15729 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_15730 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_15731 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_15732 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_15733 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_15734 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_15735 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_15736 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_15737 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_15738 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_15739 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_15740 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_15741 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_15742 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_15743 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_15744 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_15745 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_15746 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_15747 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_15748 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_15749 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_15750 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_15751 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c1122, cp_1 = c1122_p_0, cp_0 = 0;c < c1122 + 256;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15728);
										mem_vec_15728 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15729);
										mem_vec_15729 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15730);
										mem_vec_15730 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15731);
										mem_vec_15731 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15732);
										mem_vec_15732 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15733);
										mem_vec_15733 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15734);
										mem_vec_15734 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15735);
										mem_vec_15735 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15736);
										mem_vec_15736 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15737);
										mem_vec_15737 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15738);
										mem_vec_15738 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15739);
										mem_vec_15739 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15740);
										mem_vec_15740 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15741);
										mem_vec_15741 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15742);
										mem_vec_15742 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15743);
										mem_vec_15743 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15744);
										mem_vec_15744 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15745);
										mem_vec_15745 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15746);
										mem_vec_15746 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15747);
										mem_vec_15747 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15748);
										mem_vec_15748 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15749);
										mem_vec_15749 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15750);
										mem_vec_15750 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15751);
										mem_vec_15751 = vec_33;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_15728);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_15729);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_15730);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_15731);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_15732);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_15733);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_15734);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_15735);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_15736);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_15737);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_15738);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_15739);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_15740);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_15741);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_15742);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_15743);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_15744);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_15745);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_15746);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_15747);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_15748);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_15749);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_15750);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_15751);
						}
}
