
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (8, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c441_p_0, cp_1, c441, x, xp_0, x723_p_0, x724_p_0, xp_1, x723_p_1, xp_2, x723, x724, y, yp_0, y576_p_0, yp_1, y576;
IND_TYPE y577 = 0;
IND_TYPE x725 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c442 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2814 ,mem_vec_2815 ,mem_vec_2816 ,mem_vec_2817 ,mem_vec_2818 ,mem_vec_2819 ,mem_vec_2820 ,mem_vec_2821 ,mem_vec_2822 ,mem_vec_2823 ,mem_vec_2824 ,mem_vec_2825 ,mem_vec_2826 ,mem_vec_2827 ,mem_vec_2828 ,mem_vec_2829 ,mem_vec_2830 ,mem_vec_2831 ,mem_vec_2832 ,mem_vec_2833 ,mem_vec_2834 ,mem_vec_2835 ,mem_vec_2836 ,mem_vec_2837 ,mem_vec_2838 ,mem_vec_2839 ,mem_vec_2840 ,mem_vec_2841 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
y576 = 0;
y576_p_0 = 0;
x724 = 0;
x724_p_0 = 0;
y = 0;
yp_1 = 0;
x723 = 0;
x723_p_1 = 0;
c441 = 0;
c441_p_0 = 0;
					for (x = x723, xp_2 = x723_p_1, xp_1 = x723_p_0, xp_0 = 0;x < x723 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2814 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_2815 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_2816 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_2817 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_2818 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_2819 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_2820 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_2821 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_2822 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_2823 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_2824 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_2825 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								mem_vec_2826 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_2827 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_2828 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
								mem_vec_2829 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
								mem_vec_2830 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_2831 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_2832 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
								mem_vec_2833 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
								mem_vec_2834 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_2835 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_2836 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
								mem_vec_2837 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
								mem_vec_2838 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_2839 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_2840 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
								mem_vec_2841 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c441, cp_1 = c441_p_0, cp_0 = 0;c < c441 + 64;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2814);
									mem_vec_2814 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2815);
									mem_vec_2815 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2816);
									mem_vec_2816 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2817);
									mem_vec_2817 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2818);
									mem_vec_2818 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2819);
									mem_vec_2819 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2820);
									mem_vec_2820 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2821);
									mem_vec_2821 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2822);
									mem_vec_2822 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2823);
									mem_vec_2823 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2824);
									mem_vec_2824 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2825);
									mem_vec_2825 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);
									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2826);
									mem_vec_2826 = vec_19;
									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2827);
									mem_vec_2827 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2828);
									mem_vec_2828 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2829);
									mem_vec_2829 = vec_23;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);
									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2830);
									mem_vec_2830 = vec_24;
									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2831);
									mem_vec_2831 = vec_26;
									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2832);
									mem_vec_2832 = vec_27;
									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2833);
									mem_vec_2833 = vec_28;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);
									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2834);
									mem_vec_2834 = vec_29;
									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2835);
									mem_vec_2835 = vec_31;
									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2836);
									mem_vec_2836 = vec_32;
									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2837);
									mem_vec_2837 = vec_33;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);
									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2838);
									mem_vec_2838 = vec_34;
									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2839);
									mem_vec_2839 = vec_36;
									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2840);
									mem_vec_2840 = vec_37;
									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2841);
									mem_vec_2841 = vec_38;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2814);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2815);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2816);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2817);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2818);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2819);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2820);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2821);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2822);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2823);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2824);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2825);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2826);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2827);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2828);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2829);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2830);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2831);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_2832);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_2833);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2834);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2835);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_2836);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_2837);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2838);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2839);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_2840);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_2841);
					}
}
