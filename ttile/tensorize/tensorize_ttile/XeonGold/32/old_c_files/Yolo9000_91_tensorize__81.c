
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (2, f); T (1, x); T (2, y); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, x, xp_0, x92_p_0, x93_p_0, xp_1, x92_p_1, xp_2, x92, x93, y, yp_0, y69_p_0, yp_1, y69;
IND_TYPE y70 = 0;
IND_TYPE x94 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c70 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1196 ,mem_vec_1197 ,mem_vec_1198 ,mem_vec_1199 ,mem_vec_1200 ,mem_vec_1201 ,mem_vec_1202 ,mem_vec_1203 ,mem_vec_1204 ,mem_vec_1205 ,mem_vec_1206 ,mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,mem_vec_1234 ,mem_vec_1235 ,mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,mem_vec_1240 ,mem_vec_1241 ,mem_vec_1242 ,mem_vec_1243 ,mem_vec_1244 ,mem_vec_1245 ,mem_vec_1246 ,mem_vec_1247 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y69 = 0;
y69_p_0 = 0;
x93 = 0;
x93_p_0 = 0;
y = 0;
yp_1 = 0;
x92 = 0;
x92_p_1 = 0;
f = 0;
fp_0 = 0;
c69 = 0;
c69_p_0 = 0;
							for (x = x92, xp_2 = x92_p_1, xp_1 = x92_p_0, xp_0 = 0;x < x92 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1196 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_1197 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_1198 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_1199 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_1200 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_1201 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_1202 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_1203 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_1204 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_1205 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_1206 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_1207 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_1208 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_1209 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_1210 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_1211 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_1212 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_1213 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_1214 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_1215 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_1216 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_1217 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_1218 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_1219 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c69, cp_1 = c69_p_0, cp_0 = 0;c < c69 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1196);
											mem_vec_1196 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1197);
											mem_vec_1197 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1198);
											mem_vec_1198 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1199);
											mem_vec_1199 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1200);
											mem_vec_1200 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1201);
											mem_vec_1201 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1202);
											mem_vec_1202 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1203);
											mem_vec_1203 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1204);
											mem_vec_1204 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1205);
											mem_vec_1205 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1206);
											mem_vec_1206 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1207);
											mem_vec_1207 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1208);
											mem_vec_1208 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1209);
											mem_vec_1209 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1210);
											mem_vec_1210 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1211);
											mem_vec_1211 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1212);
											mem_vec_1212 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1213);
											mem_vec_1213 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1214);
											mem_vec_1214 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1215);
											mem_vec_1215 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1216);
											mem_vec_1216 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1217);
											mem_vec_1217 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1218);
											mem_vec_1218 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1219);
											mem_vec_1219 = vec_33;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1196);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1197);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1198);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1199);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1200);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1201);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1202);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1203);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1204);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1205);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1206);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1207);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1208);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1209);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1210);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1211);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1212);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1213);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_1214);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_1215);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1216);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1217);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_1218);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_1219);
							}
}
