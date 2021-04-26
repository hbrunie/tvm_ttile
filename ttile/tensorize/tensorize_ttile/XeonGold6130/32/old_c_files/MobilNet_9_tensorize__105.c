
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (8, c); T (1, y); T (16, f); T (8, c); T (2, c)]
*/
IND_TYPE c, cp_0, c365_p_0, c366_p_0, c367_p_0, cp_1, c365_p_1, c366_p_1, cp_2, c365_p_2, cp_3, c365, c366, c367, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y146 = 0;
IND_TYPE x146 = 0;
IND_TYPE h122 = 0;
IND_TYPE w123 = 0;
IND_TYPE c368 = 0;
IND_TYPE f146 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2044 ,mem_vec_2045 ,mem_vec_2046 ,mem_vec_2047 ,mem_vec_2048 ,mem_vec_2049 ,mem_vec_2050 ,mem_vec_2051 ,mem_vec_2052 ,mem_vec_2053 ,mem_vec_2054 ,mem_vec_2055 ,mem_vec_2056 ,mem_vec_2057 ,mem_vec_2058 ,mem_vec_2059 ,mem_vec_2060 ,mem_vec_2061 ,mem_vec_2062 ,mem_vec_2063 ,mem_vec_2064 ,mem_vec_2065 ,mem_vec_2066 ,mem_vec_2067 ,mem_vec_2068 ,mem_vec_2069 ,mem_vec_2070 ,mem_vec_2071 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 2) (1024 / 512)
c367 = 0;
c367_p_0 = 0;
c366 = 0;
c366_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
c365 = 0;
c365_p_2 = 0;
x = 0;
xp_0 = 0;
						for (h = h122, hp_0 = 0;h < h122 + 3;h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 8, f = 64
							// T (w, 3) (3 / 1)
							for (w = w123, wp_0 = 0;w < w123 + 3;w += 1, wp_0 += 1){
										mem_vec_2044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_2047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_2048 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2049 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2050 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_2051 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_2052 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2053 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2054 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_2055 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_2056 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2057 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2058 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_2059 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_2060 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_2061 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_2062 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_2063 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_2064 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_2065 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_2066 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_2067 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										mem_vec_2068 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_2069 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_2070 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
										mem_vec_2071 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c365, cp_3 = c365_p_2, cp_2 = c365_p_1, cp_1 = c365_p_0, cp_0 = 0;c < c365 + 8;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2044);
											mem_vec_2044 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2045);
											mem_vec_2045 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2046);
											mem_vec_2046 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2047);
											mem_vec_2047 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2048);
											mem_vec_2048 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2049);
											mem_vec_2049 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2050);
											mem_vec_2050 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2051);
											mem_vec_2051 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2052);
											mem_vec_2052 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2053);
											mem_vec_2053 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2054);
											mem_vec_2054 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2055);
											mem_vec_2055 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2056);
											mem_vec_2056 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2057);
											mem_vec_2057 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2058);
											mem_vec_2058 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2059);
											mem_vec_2059 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2060);
											mem_vec_2060 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2061);
											mem_vec_2061 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2062);
											mem_vec_2062 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2063);
											mem_vec_2063 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2064);
											mem_vec_2064 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2065);
											mem_vec_2065 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2066);
											mem_vec_2066 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2067);
											mem_vec_2067 = vec_33;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2068);
											mem_vec_2068 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2069);
											mem_vec_2069 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2070);
											mem_vec_2070 = vec_37;
											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2071);
											mem_vec_2071 = vec_38;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2044);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2045);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2046);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2047);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2048);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2049);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2050);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2051);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2052);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2053);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2054);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2055);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2056);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2057);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2058);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2059);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2060);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2061);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_2062);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_2063);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_2064);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_2065);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_2066);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_2067);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_2068);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_2069);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_2070);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_2071);
							}
						}
}
