
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (1, c);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (8, f);
  T (4, c); T (1, y)]
*/
IND_TYPE c, cp_0, c484_p_0, c485_p_0, cp_1, c484_p_1, cp_2, c484, c485, f, fp_0, x, xp_0, y, yp_0, y363_p_0, yp_1, y363;
IND_TYPE y364 = 0;
IND_TYPE x242 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c486 = 0;
IND_TYPE f242 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,mem_vec_4831 ,mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,mem_vec_4844 ,mem_vec_4845 ,mem_vec_4846 ,mem_vec_4847 ,mem_vec_4848 ,mem_vec_4849 ,mem_vec_4850 ,mem_vec_4851 ,mem_vec_4852 ,mem_vec_4853 ,mem_vec_4854 ,mem_vec_4855 ,mem_vec_4856 ,mem_vec_4857 ,mem_vec_4858 ,mem_vec_4859 ,mem_vec_4860 ,mem_vec_4861 ,mem_vec_4862 ,mem_vec_4863 ,mem_vec_4864 ,mem_vec_4865 ,mem_vec_4866 ,mem_vec_4867 ,mem_vec_4868 ,mem_vec_4869 ,mem_vec_4870 ,mem_vec_4871 ,mem_vec_4872 ,mem_vec_4873 ,mem_vec_4874 ,mem_vec_4875 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y363 = 0;
y363_p_0 = 0;
c485 = 0;
c485_p_0 = 0;
		for (f = f242, fp_0 = 0;f < f242 + 512;f += 64, fp_0 += 64){
				for (y = y363, yp_1 = y363_p_0, yp_0 = 0;y < y363 + 10;y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c484 = c485, c484_p_1 = c485_p_0, c484_p_0 = 0;c484 < c485 + 256;c484 += 256, c484_p_1 += 256, c484_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x242, xp_0 = 0;x < x242 + 17;x += 1, xp_0 += 1){
									mem_vec_4828 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_4829 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_4830 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_4831 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_4832 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_4833 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_4834 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_4835 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_4836 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_4837 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_4838 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_4839 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_4840 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_4841 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_4842 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_4843 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_4844 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_4845 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_4846 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_4847 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c484, cp_2 = c484_p_1, cp_1 = c484_p_0, cp_0 = 0;c < c484 + 256;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4828);
										mem_vec_4828 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4829);
										mem_vec_4829 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4830);
										mem_vec_4830 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4831);
										mem_vec_4831 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4832);
										mem_vec_4832 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4833);
										mem_vec_4833 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4834);
										mem_vec_4834 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4835);
										mem_vec_4835 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4836);
										mem_vec_4836 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4837);
										mem_vec_4837 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4838);
										mem_vec_4838 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4839);
										mem_vec_4839 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4840);
										mem_vec_4840 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4841);
										mem_vec_4841 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4842);
										mem_vec_4842 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4843);
										mem_vec_4843 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4844);
										mem_vec_4844 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4845);
										mem_vec_4845 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4846);
										mem_vec_4846 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4847);
										mem_vec_4847 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4828);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4829);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4830);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4831);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4832);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4833);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4834);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4835);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4836);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4837);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_4838);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_4839);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4840);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4841);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_4842);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_4843);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4844);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4845);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_4846);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_4847);
						}
					}
				}
				for (y = y363 + 10, yp_1 = y363_p_0, yp_0 = 0;y < y363 + 10 + 7;y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c484 = c485, c484_p_1 = c485_p_0, c484_p_0 = 0;c484 < c485 + 256;c484 += 256, c484_p_1 += 256, c484_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x242, xp_0 = 0;x < x242 + 17;x += 1, xp_0 += 1){
									mem_vec_4848 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_4849 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_4850 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_4851 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_4852 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_4853 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_4854 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_4855 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_4856 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_4857 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_4858 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_4859 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_4860 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_4861 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_4862 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_4863 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_4864 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_4865 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_4866 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_4867 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_4868 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_4869 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_4870 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_4871 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_4872 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_4873 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_4874 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_4875 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c484, cp_2 = c484_p_1, cp_1 = c484_p_0, cp_0 = 0;c < c484 + 256;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4848);
										mem_vec_4848 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4849);
										mem_vec_4849 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4850);
										mem_vec_4850 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4851);
										mem_vec_4851 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4852);
										mem_vec_4852 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4853);
										mem_vec_4853 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4854);
										mem_vec_4854 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4855);
										mem_vec_4855 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4856);
										mem_vec_4856 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4857);
										mem_vec_4857 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4858);
										mem_vec_4858 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4859);
										mem_vec_4859 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4860);
										mem_vec_4860 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4861);
										mem_vec_4861 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4862);
										mem_vec_4862 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4863);
										mem_vec_4863 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4864);
										mem_vec_4864 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4865);
										mem_vec_4865 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4866);
										mem_vec_4866 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4867);
										mem_vec_4867 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4868);
										mem_vec_4868 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4869);
										mem_vec_4869 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4870);
										mem_vec_4870 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4871);
										mem_vec_4871 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4872);
										mem_vec_4872 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4873);
										mem_vec_4873 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4874);
										mem_vec_4874 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4875);
										mem_vec_4875 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4848);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4849);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4850);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4851);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4852);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4853);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4854);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4855);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4856);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4857);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_4858);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_4859);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4860);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4861);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_4862);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_4863);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4864);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4865);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_4866);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_4867);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4868);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4869);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_4870);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_4871);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4872);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4873);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_4874);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_4875);
						}
					}
				}
		}
}
