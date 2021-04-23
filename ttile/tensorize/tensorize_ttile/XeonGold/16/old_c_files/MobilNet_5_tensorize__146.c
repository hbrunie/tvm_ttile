
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (8, c); T (2, f); T (4, y); T (2, x); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c159_p_0, cp_1, c159, f, fp_0, f196_p_0, f197_p_0, fp_1, f196_p_1, fp_2, f196, f197, h, hp_0, w, wp_0, x, xp_0, x159_p_0, xp_1, x159, y, yp_0;
IND_TYPE y114 = 0;
IND_TYPE x160 = 0;
IND_TYPE h102 = 0;
IND_TYPE w64 = 0;
IND_TYPE c160 = 0;
IND_TYPE f198 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,mem_vec_1234 ,mem_vec_1235 ,mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
f197 = 0;
f197_p_0 = 0;
f196 = 0;
f196_p_1 = 0;
x159 = 0;
x159_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c159 = 0;
c159_p_0 = 0;
						for (w = w64, wp_0 = 0;w < w64 + 3;w += 1, wp_0 += 1){
							// y = 7, x = 14, h = 3, w = 1, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x159, xp_1 = x159_p_0, xp_0 = 0;x < x159 + 14;x += 1, xp_1 += 1, xp_0 += 1){
								// y = 7, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h102, hp_0 = 0;h < h102 + 3;h += 1, hp_0 += 1){
											mem_vec_1212 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_1213 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_1214 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_1215 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_1216 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_1217 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_1218 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_1219 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_1220 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_1221 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_1222 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_1223 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											mem_vec_1224 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_1225 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_1226 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
											mem_vec_1227 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
											mem_vec_1228 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_1229 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_1230 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
											mem_vec_1231 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
											mem_vec_1232 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_1233 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_1234 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
											mem_vec_1235 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
											mem_vec_1236 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_1237 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_1238 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
											mem_vec_1239 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c159, cp_1 = c159_p_0, cp_0 = 0;c < c159 + 32;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1212);
												mem_vec_1212 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1213);
												mem_vec_1213 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1214);
												mem_vec_1214 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1215);
												mem_vec_1215 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1216);
												mem_vec_1216 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1217);
												mem_vec_1217 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1218);
												mem_vec_1218 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1219);
												mem_vec_1219 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1220);
												mem_vec_1220 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1221);
												mem_vec_1221 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1222);
												mem_vec_1222 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1223);
												mem_vec_1223 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1224);
												mem_vec_1224 = vec_19;
												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1225);
												mem_vec_1225 = vec_21;
												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1226);
												mem_vec_1226 = vec_22;
												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1227);
												mem_vec_1227 = vec_23;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1228);
												mem_vec_1228 = vec_24;
												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1229);
												mem_vec_1229 = vec_26;
												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1230);
												mem_vec_1230 = vec_27;
												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1231);
												mem_vec_1231 = vec_28;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1232);
												mem_vec_1232 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1233);
												mem_vec_1233 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1234);
												mem_vec_1234 = vec_32;
												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1235);
												mem_vec_1235 = vec_33;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1236);
												mem_vec_1236 = vec_34;
												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1237);
												mem_vec_1237 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1238);
												mem_vec_1238 = vec_37;
												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1239);
												mem_vec_1239 = vec_38;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1212);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1213);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1214);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1215);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1216);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1217);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1218);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1219);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1220);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1221);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1222);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1223);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1224);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1225);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1226);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1227);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1228);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1229);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_1230);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_1231);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1232);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1233);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_1234);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_1235);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1236);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1237);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_1238);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_1239);
								}
							}
						}
}
