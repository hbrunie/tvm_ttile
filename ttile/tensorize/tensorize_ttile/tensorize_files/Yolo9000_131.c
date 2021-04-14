
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (34, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]; T (8, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c720_p_0, cp_1, c720, f, fp_0, x, xp_0, x960_p_0, x961_p_0, xp_1, x960_p_1, xp_2, x960, x961, y, yp_0;
IND_TYPE y480 = 0;
IND_TYPE x962 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c721 = 0;
IND_TYPE f480 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10028 ,mem_vec_10029 ,mem_vec_10030 ,mem_vec_10031 ,mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,mem_vec_10052 ,mem_vec_10053 ,mem_vec_10054 ,mem_vec_10055 ,mem_vec_10056 ,mem_vec_10057 ,mem_vec_10058 ,mem_vec_10059 ,mem_vec_10060 ,mem_vec_10061 ,mem_vec_10062 ,mem_vec_10063 ,mem_vec_10064 ,mem_vec_10065 ,mem_vec_10066 ,mem_vec_10067 ,mem_vec_10068 ,mem_vec_10069 ,mem_vec_10070 ,mem_vec_10071 ,mem_vec_10072 ,mem_vec_10073 ,mem_vec_10074 ,mem_vec_10075 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
x961 = 0;
x961_p_0 = 0;
c720 = 0;
c720_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x960 = 0;
x960_p_1 = 0;
						for (x = x960, xp_2 = x960_p_1, xp_1 = x960_p_0, xp_0 = 0;x < x960 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10028 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_10029 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_10030 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_10031 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_10032 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_10033 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_10034 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_10035 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_10036 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_10037 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_10038 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_10039 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_10040 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_10041 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_10042 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_10043 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
									mem_vec_10044 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_10045 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
									mem_vec_10046 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
									mem_vec_10047 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c720, cp_1 = c720_p_0, cp_0 = 0;c < c720 + 2;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10028);
										mem_vec_10028 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10029);
										mem_vec_10029 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10030);
										mem_vec_10030 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10031);
										mem_vec_10031 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10032);
										mem_vec_10032 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10033);
										mem_vec_10033 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10034);
										mem_vec_10034 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10035);
										mem_vec_10035 = vec_13;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10036);
										mem_vec_10036 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10037);
										mem_vec_10037 = vec_16;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10038);
										mem_vec_10038 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10039);
										mem_vec_10039 = vec_19;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10040);
										mem_vec_10040 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10041);
										mem_vec_10041 = vec_22;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10042);
										mem_vec_10042 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10043);
										mem_vec_10043 = vec_25;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10044);
										mem_vec_10044 = vec_26;
										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10045);
										mem_vec_10045 = vec_28;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10046);
										mem_vec_10046 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10047);
										mem_vec_10047 = vec_31;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10028);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10029);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10030);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10031);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_10032);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_10033);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_10034);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_10035);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_10036);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_10037);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_10038);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_10039);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_10040);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_10041);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_10042);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_10043);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_10044);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_10045);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_10046);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_10047);
						}
}
