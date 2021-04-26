
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (1, x); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, x, xp_0, x108_p_0, x109_p_0, xp_1, x108_p_1, xp_2, x108, x109, y, yp_0, y73_p_0, yp_1, y73;
IND_TYPE y74 = 0;
IND_TYPE x110 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c82 = 0;
IND_TYPE f54 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,mem_vec_1234 ,mem_vec_1235 ,mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,mem_vec_1240 ,mem_vec_1241 ,mem_vec_1242 ,mem_vec_1243 ,mem_vec_1244 ,mem_vec_1245 ,mem_vec_1246 ,mem_vec_1247 ,mem_vec_1248 ,mem_vec_1249 ,mem_vec_1250 ,mem_vec_1251 ,mem_vec_1252 ,mem_vec_1253 ,mem_vec_1254 ,mem_vec_1255 ,mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y73 = 0;
y73_p_0 = 0;
x109 = 0;
x109_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
x108 = 0;
x108_p_1 = 0;
c81 = 0;
c81_p_0 = 0;
							for (x = x108, xp_2 = x108_p_1, xp_1 = x108_p_0, xp_0 = 0;x < x108 + 34;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1216 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_1217 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_1218 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_1219 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_1220 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_1221 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_1222 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_1223 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_1224 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_1225 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_1226 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_1227 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_1228 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_1229 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_1230 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_1231 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_1232 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_1233 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_1234 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_1235 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c81, cp_1 = c81_p_0, cp_0 = 0;c < c81 + 512;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1216);
											mem_vec_1216 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1217);
											mem_vec_1217 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1218);
											mem_vec_1218 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1219);
											mem_vec_1219 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1220);
											mem_vec_1220 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1221);
											mem_vec_1221 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1222);
											mem_vec_1222 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1223);
											mem_vec_1223 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1224);
											mem_vec_1224 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1225);
											mem_vec_1225 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1226);
											mem_vec_1226 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1227);
											mem_vec_1227 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1228);
											mem_vec_1228 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1229);
											mem_vec_1229 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1230);
											mem_vec_1230 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1231);
											mem_vec_1231 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1232);
											mem_vec_1232 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1233);
											mem_vec_1233 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1234);
											mem_vec_1234 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1235);
											mem_vec_1235 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1216);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1217);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1218);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1219);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1220);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1221);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1222);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1223);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1224);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1225);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1226);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1227);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1228);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1229);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1230);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1231);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1232);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1233);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1234);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1235);
							}
}
