
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (4, c); T (17, x); T (1, y)]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, x, xp_0, x69_p_0, xp_1, x69, y, yp_0, y69_p_0, yp_1, y69;
IND_TYPE y70 = 0;
IND_TYPE x70 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c70 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y69 = 0;
y69_p_0 = 0;
x69 = 0;
x69_p_0 = 0;
c69 = 0;
c69_p_0 = 0;
			for (f = f46, fp_0 = 0;f < f46 + 512;f += 32, fp_0 += 32){
					for (y = y69, yp_1 = y69_p_0, yp_0 = 0;y < y69 + 12;y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x69, xp_1 = x69_p_0, xp_0 = 0;x < x69 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_828 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_829 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_830 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_831 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_832 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_833 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_834 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_835 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_836 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_837 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_838 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_839 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_840 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_841 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_842 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_843 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c69, cp_1 = c69_p_0, cp_0 = 0;c < c69 + 256;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_828);
										mem_vec_828 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_829);
										mem_vec_829 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_830);
										mem_vec_830 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_831);
										mem_vec_831 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_832);
										mem_vec_832 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_833);
										mem_vec_833 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_834);
										mem_vec_834 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_835);
										mem_vec_835 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_836);
										mem_vec_836 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_837);
										mem_vec_837 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_838);
										mem_vec_838 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_839);
										mem_vec_839 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_840);
										mem_vec_840 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_841);
										mem_vec_841 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_842);
										mem_vec_842 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_843);
										mem_vec_843 = vec_23;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_828);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_829);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_830);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_831);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_832);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_833);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_834);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_835);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_836);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_837);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_838);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_839);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_840);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_841);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_842);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_843);
						}
					}
					for (y = y69 + 12, yp_1 = y69_p_0, yp_0 = 0;y < y69 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x69, xp_1 = x69_p_0, xp_0 = 0;x < x69 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_844 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_845 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
									mem_vec_846 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_847 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
									mem_vec_848 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_849 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
									mem_vec_850 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_851 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
									mem_vec_852 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_853 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
									mem_vec_854 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_855 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
									mem_vec_856 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_857 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
									mem_vec_858 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_859 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
									mem_vec_860 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_861 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
									mem_vec_862 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_863 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c69, cp_1 = c69_p_0, cp_0 = 0;c < c69 + 256;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_844);
										mem_vec_844 = vec_0;
										vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_845);
										mem_vec_845 = vec_3;
										vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_846);
										mem_vec_846 = vec_5;
										vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_847);
										mem_vec_847 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);
										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_848);
										mem_vec_848 = vec_9;
										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_849);
										mem_vec_849 = vec_11;
										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_850);
										mem_vec_850 = vec_12;
										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_851);
										mem_vec_851 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);
										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_852);
										mem_vec_852 = vec_14;
										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_853);
										mem_vec_853 = vec_16;
										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_854);
										mem_vec_854 = vec_17;
										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_855);
										mem_vec_855 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);
										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_856);
										mem_vec_856 = vec_19;
										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_857);
										mem_vec_857 = vec_21;
										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_858);
										mem_vec_858 = vec_22;
										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_859);
										mem_vec_859 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_860);
										mem_vec_860 = vec_24;
										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_861);
										mem_vec_861 = vec_26;
										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_862);
										mem_vec_862 = vec_27;
										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_863);
										mem_vec_863 = vec_28;
									}
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_844);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_845);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_846);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_847);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_848);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_849);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_850);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_851);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_852);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_853);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_854);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_855);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_856);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_857);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_858);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_859);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_860);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_861);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_862);
								_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_863);
						}
					}
			}
}
