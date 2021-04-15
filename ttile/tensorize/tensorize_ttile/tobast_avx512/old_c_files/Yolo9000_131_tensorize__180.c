
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (64, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1188_p_0, cp_1, c1188, f, fp_0, x, xp_0, x1584_p_0, x1585_p_0, xp_1, x1584_p_1, xp_2, x1584, x1585, y, yp_0;
IND_TYPE y792 = 0;
IND_TYPE x1586 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1189 = 0;
IND_TYPE f792 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16872 ,mem_vec_16873 ,mem_vec_16874 ,mem_vec_16875 ,mem_vec_16876 ,mem_vec_16877 ,mem_vec_16878 ,mem_vec_16879 ,mem_vec_16880 ,mem_vec_16881 ,mem_vec_16882 ,mem_vec_16883 ,mem_vec_16884 ,mem_vec_16885 ,mem_vec_16886 ,mem_vec_16887 ,mem_vec_16888 ,mem_vec_16889 ,mem_vec_16890 ,mem_vec_16891 ,mem_vec_16892 ,mem_vec_16893 ,mem_vec_16894 ,mem_vec_16895 ,mem_vec_16896 ,mem_vec_16897 ,mem_vec_16898 ,mem_vec_16899 ,mem_vec_16900 ,mem_vec_16901 ,mem_vec_16902 ,mem_vec_16903 ,mem_vec_16904 ,mem_vec_16905 ,mem_vec_16906 ,mem_vec_16907 ,mem_vec_16908 ,mem_vec_16909 ,mem_vec_16910 ,mem_vec_16911 ,mem_vec_16912 ,mem_vec_16913 ,mem_vec_16914 ,mem_vec_16915 ,mem_vec_16916 ,mem_vec_16917 ,mem_vec_16918 ,mem_vec_16919 ,mem_vec_16920 ,mem_vec_16921 ,mem_vec_16922 ,mem_vec_16923 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 34) (34 / 1)
x1585 = 0;
x1585_p_0 = 0;
c1188 = 0;
c1188_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1584 = 0;
x1584_p_1 = 0;
						for (x = x1584, xp_2 = x1584_p_1, xp_1 = x1584_p_0, xp_0 = 0;x < x1584 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_16873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_16874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_16875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_16876 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_16877 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_16878 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_16879 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_16880 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_16881 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_16882 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_16883 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_16884 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_16885 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_16886 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_16887 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_16888 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_16889 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_16890 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_16891 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_16892 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_16893 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_16894 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_16895 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1188, cp_1 = c1188_p_0, cp_0 = 0;c < c1188 + 8;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16872);
										mem_vec_16872 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16873);
										mem_vec_16873 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16874);
										mem_vec_16874 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16875);
										mem_vec_16875 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16876);
										mem_vec_16876 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16877);
										mem_vec_16877 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16878);
										mem_vec_16878 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16879);
										mem_vec_16879 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16880);
										mem_vec_16880 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16881);
										mem_vec_16881 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16882);
										mem_vec_16882 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16883);
										mem_vec_16883 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16884);
										mem_vec_16884 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16885);
										mem_vec_16885 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16886);
										mem_vec_16886 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16887);
										mem_vec_16887 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16888);
										mem_vec_16888 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16889);
										mem_vec_16889 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16890);
										mem_vec_16890 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16891);
										mem_vec_16891 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16892);
										mem_vec_16892 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16893);
										mem_vec_16893 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16894);
										mem_vec_16894 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16895);
										mem_vec_16895 = vec_33;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_16872);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_16873);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_16874);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_16875);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_16876);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_16877);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_16878);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_16879);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_16880);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_16881);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_16882);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_16883);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_16884);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_16885);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_16886);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_16887);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_16888);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_16889);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_16890);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_16891);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_16892);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_16893);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_16894);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_16895);
						}
}
