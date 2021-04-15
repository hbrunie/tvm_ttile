
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1068_p_0, cp_1, c1068, f, fp_0, x, xp_0, x1424_p_0, x1425_p_0, xp_1, x1424_p_1, xp_2, x1424, x1425, y, yp_0;
IND_TYPE y712 = 0;
IND_TYPE x1426 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1069 = 0;
IND_TYPE f712 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14792 ,mem_vec_14793 ,mem_vec_14794 ,mem_vec_14795 ,mem_vec_14796 ,mem_vec_14797 ,mem_vec_14798 ,mem_vec_14799 ,mem_vec_14800 ,mem_vec_14801 ,mem_vec_14802 ,mem_vec_14803 ,mem_vec_14804 ,mem_vec_14805 ,mem_vec_14806 ,mem_vec_14807 ,mem_vec_14808 ,mem_vec_14809 ,mem_vec_14810 ,mem_vec_14811 ,mem_vec_14812 ,mem_vec_14813 ,mem_vec_14814 ,mem_vec_14815 ,mem_vec_14816 ,mem_vec_14817 ,mem_vec_14818 ,mem_vec_14819 ,mem_vec_14820 ,mem_vec_14821 ,mem_vec_14822 ,mem_vec_14823 ,mem_vec_14824 ,mem_vec_14825 ,mem_vec_14826 ,mem_vec_14827 ,mem_vec_14828 ,mem_vec_14829 ,mem_vec_14830 ,mem_vec_14831 ,mem_vec_14832 ,mem_vec_14833 ,mem_vec_14834 ,mem_vec_14835 ,mem_vec_14836 ,mem_vec_14837 ,mem_vec_14838 ,mem_vec_14839 ,mem_vec_14840 ,mem_vec_14841 ,mem_vec_14842 ,mem_vec_14843 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
x1425 = 0;
x1425_p_0 = 0;
c1068 = 0;
c1068_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1424 = 0;
x1424_p_1 = 0;
						for (x = x1424, xp_2 = x1424_p_1, xp_1 = x1424_p_0, xp_0 = 0;x < x1424 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_14793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_14794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_14795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_14796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_14797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_14798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_14799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_14800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_14801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_14802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_14803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_14804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_14805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_14806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_14807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_14808 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_14809 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_14810 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_14811 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_14812 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_14813 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_14814 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_14815 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1068, cp_1 = c1068_p_0, cp_0 = 0;c < c1068 + 2;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14792);
										mem_vec_14792 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14793);
										mem_vec_14793 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14794);
										mem_vec_14794 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14795);
										mem_vec_14795 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14796);
										mem_vec_14796 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14797);
										mem_vec_14797 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14798);
										mem_vec_14798 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14799);
										mem_vec_14799 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14800);
										mem_vec_14800 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14801);
										mem_vec_14801 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14802);
										mem_vec_14802 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14803);
										mem_vec_14803 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14804);
										mem_vec_14804 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14805);
										mem_vec_14805 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14806);
										mem_vec_14806 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14807);
										mem_vec_14807 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14808);
										mem_vec_14808 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14809);
										mem_vec_14809 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14810);
										mem_vec_14810 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14811);
										mem_vec_14811 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14812);
										mem_vec_14812 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14813);
										mem_vec_14813 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14814);
										mem_vec_14814 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14815);
										mem_vec_14815 = vec_33;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14792);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14793);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_14794);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_14795);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14796);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14797);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_14798);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_14799);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14800);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14801);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_14802);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_14803);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14804);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14805);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_14806);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_14807);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_14808);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_14809);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_14810);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_14811);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_14812);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_14813);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_14814);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_14815);
						}
}
