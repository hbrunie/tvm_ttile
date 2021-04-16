
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (16, c);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (8, f);
  T (1, c); T (1, y)]
*/
IND_TYPE c, cp_0, c284_p_0, c285_p_0, cp_1, c284_p_1, cp_2, c284, c285, f, fp_0, x, xp_0, y, yp_0, y213_p_0, yp_1, y213;
IND_TYPE y214 = 0;
IND_TYPE x142 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c286 = 0;
IND_TYPE f142 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,mem_vec_2940 ,mem_vec_2941 ,mem_vec_2942 ,mem_vec_2943 ,mem_vec_2944 ,mem_vec_2945 ,mem_vec_2946 ,mem_vec_2947 ,mem_vec_2948 ,mem_vec_2949 ,mem_vec_2950 ,mem_vec_2951 ,mem_vec_2952 ,mem_vec_2953 ,mem_vec_2954 ,mem_vec_2955 ,mem_vec_2956 ,mem_vec_2957 ,mem_vec_2958 ,mem_vec_2959 ,mem_vec_2960 ,mem_vec_2961 ,mem_vec_2962 ,mem_vec_2963 ,mem_vec_2964 ,mem_vec_2965 ,mem_vec_2966 ,mem_vec_2967 ,mem_vec_2968 ,mem_vec_2969 ,mem_vec_2970 ,mem_vec_2971 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y213 = 0;
y213_p_0 = 0;
c285 = 0;
c285_p_0 = 0;
		for (f = f142, fp_0 = 0;f < f142 + 512;f += 64, fp_0 += 64){
				for (y = y213, yp_1 = y213_p_0, yp_0 = 0;y < y213 + 12;y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c284 = c285, c284_p_1 = c285_p_0, c284_p_0 = 0;c284 < c285 + 1024;c284 += 64, c284_p_1 += 64, c284_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x142, xp_0 = 0;x < x142 + 17;x += 1, xp_0 += 1){
									mem_vec_2936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_2937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_2938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_2939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_2940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_2941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_2942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_2943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_2944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_2945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_2946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_2947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_2948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_2949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_2950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_2951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c284, cp_2 = c284_p_1, cp_1 = c284_p_0, cp_0 = 0;c < c284 + 64;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2936);
										mem_vec_2936 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2937);
										mem_vec_2937 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2938);
										mem_vec_2938 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2939);
										mem_vec_2939 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2940);
										mem_vec_2940 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2941);
										mem_vec_2941 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2942);
										mem_vec_2942 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2943);
										mem_vec_2943 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2944);
										mem_vec_2944 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2945);
										mem_vec_2945 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2946);
										mem_vec_2946 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2947);
										mem_vec_2947 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2948);
										mem_vec_2948 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2949);
										mem_vec_2949 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2950);
										mem_vec_2950 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2951);
										mem_vec_2951 = vec_23;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2936);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2937);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2938);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2939);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2940);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2941);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2942);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2943);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2944);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2945);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2946);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2947);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2948);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2949);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2950);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2951);
						}
					}
				}
				for (y = y213 + 12, yp_1 = y213_p_0, yp_0 = 0;y < y213 + 12 + 5;y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c284 = c285, c284_p_1 = c285_p_0, c284_p_0 = 0;c284 < c285 + 1024;c284 += 64, c284_p_1 += 64, c284_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x142, xp_0 = 0;x < x142 + 17;x += 1, xp_0 += 1){
									mem_vec_2952 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_2953 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_2954 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_2955 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_2956 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_2957 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_2958 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_2959 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_2960 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_2961 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_2962 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_2963 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_2964 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_2965 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_2966 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_2967 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_2968 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_2969 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_2970 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_2971 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c284, cp_2 = c284_p_1, cp_1 = c284_p_0, cp_0 = 0;c < c284 + 64;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2952);
										mem_vec_2952 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2953);
										mem_vec_2953 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2954);
										mem_vec_2954 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2955);
										mem_vec_2955 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2956);
										mem_vec_2956 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2957);
										mem_vec_2957 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2958);
										mem_vec_2958 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2959);
										mem_vec_2959 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2960);
										mem_vec_2960 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2961);
										mem_vec_2961 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2962);
										mem_vec_2962 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2963);
										mem_vec_2963 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2964);
										mem_vec_2964 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2965);
										mem_vec_2965 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2966);
										mem_vec_2966 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2967);
										mem_vec_2967 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2968);
										mem_vec_2968 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2969);
										mem_vec_2969 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2970);
										mem_vec_2970 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2971);
										mem_vec_2971 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2952);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2953);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2954);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2955);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2956);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2957);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2958);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2959);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2960);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2961);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2962);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2963);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2964);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2965);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2966);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2967);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2968);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2969);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_2970);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_2971);
						}
					}
				}
		}
}
