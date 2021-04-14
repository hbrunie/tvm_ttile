
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (8, c); T (8, x);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c700_p_0, c701_p_0, cp_1, c700_p_1, cp_2, c700, c701, h, hp_0, w, wp_0, x, xp_0, x770_p_0, xp_1, x770, y, yp_0;
IND_TYPE y420 = 0;
IND_TYPE x771 = 0;
IND_TYPE h384 = 0;
IND_TYPE w396 = 0;
IND_TYPE c702 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7044 ,mem_vec_7045 ,mem_vec_7046 ,mem_vec_7047 ,mem_vec_7048 ,mem_vec_7049 ,mem_vec_7050 ,mem_vec_7051 ,mem_vec_7052 ,mem_vec_7053 ,mem_vec_7054 ,mem_vec_7055 ,mem_vec_7056 ,mem_vec_7057 ,mem_vec_7058 ,mem_vec_7059 ,mem_vec_7060 ,mem_vec_7061 ,mem_vec_7062 ,mem_vec_7063 ,mem_vec_7064 ,mem_vec_7065 ,mem_vec_7066 ,mem_vec_7067 ,mem_vec_7068 ,mem_vec_7069 ,mem_vec_7070 ,mem_vec_7071 ,mem_vec_7072 ,mem_vec_7073 ,mem_vec_7074 ,mem_vec_7075 ,mem_vec_7076 ,mem_vec_7077 ,mem_vec_7078 ,mem_vec_7079 ,mem_vec_7080 ,mem_vec_7081 ,mem_vec_7082 ,mem_vec_7083 ,mem_vec_7084 ,mem_vec_7085 ,mem_vec_7086 ,mem_vec_7087 ,mem_vec_7088 ,mem_vec_7089 ,mem_vec_7090 ,mem_vec_7091 ,mem_vec_7092 ,mem_vec_7093 ,mem_vec_7094 ,mem_vec_7095 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 8) (64 / 8)
c701 = 0;
c701_p_0 = 0;
y = 0;
yp_0 = 0;
x770 = 0;
x770_p_0 = 0;
c700 = 0;
c700_p_1 = 0;
					for (h = h384, hp_0 = 0;h < h384 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
						// T (w, 3) (3 / 1)
						for (w = w396, wp_0 = 0;w < w396 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 1, c = 1, f = 64
							// T (x, 7) (7 / 1)
							for (x = x770, xp_1 = x770_p_0, xp_0 = 0;x < x770 + 7;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_7045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_7046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_7047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_7048 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_7049 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_7050 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_7051 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_7052 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_7053 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_7054 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_7055 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_7056 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_7057 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_7058 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_7059 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_7060 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_7061 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_7062 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_7063 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_7064 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_7065 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_7066 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_7067 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
										// T (c, 1) (1 / 1)
										for (c = c700, cp_2 = c700_p_1, cp_1 = c700_p_0, cp_0 = 0;c < c700 + 1;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7044);
											mem_vec_7044 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7045);
											mem_vec_7045 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7046);
											mem_vec_7046 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7047);
											mem_vec_7047 = vec_7;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7048);
											mem_vec_7048 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7049);
											mem_vec_7049 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7050);
											mem_vec_7050 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7051);
											mem_vec_7051 = vec_13;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7052);
											mem_vec_7052 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7053);
											mem_vec_7053 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7054);
											mem_vec_7054 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7055);
											mem_vec_7055 = vec_18;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7056);
											mem_vec_7056 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7057);
											mem_vec_7057 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7058);
											mem_vec_7058 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7059);
											mem_vec_7059 = vec_23;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7060);
											mem_vec_7060 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7061);
											mem_vec_7061 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7062);
											mem_vec_7062 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7063);
											mem_vec_7063 = vec_28;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7064);
											mem_vec_7064 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7065);
											mem_vec_7065 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7066);
											mem_vec_7066 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7067);
											mem_vec_7067 = vec_33;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7044);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7045);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_7046);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_7047);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7048);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7049);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_7050);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_7051);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7052);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7053);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_7054);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_7055);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7056);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7057);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_7058);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_7059);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7060);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7061);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_7062);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_7063);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7064);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7065);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_7066);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_7067);
							}
						}
					}
}
