
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (17, x); T (1, y); T (8, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]]
*/
IND_TYPE c, cp_0, c441_p_0, cp_1, c441, f, fp_0, x, xp_0, x588_p_0, x589_p_0, xp_1, x588_p_1, xp_2, x588, x589, y, yp_0, y433_p_0, yp_1, y433;
IND_TYPE y434 = 0;
IND_TYPE x590 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c442 = 0;
IND_TYPE f294 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6228 ,mem_vec_6229 ,mem_vec_6230 ,mem_vec_6231 ,mem_vec_6232 ,mem_vec_6233 ,mem_vec_6234 ,mem_vec_6235 ,mem_vec_6236 ,mem_vec_6237 ,mem_vec_6238 ,mem_vec_6239 ,mem_vec_6240 ,mem_vec_6241 ,mem_vec_6242 ,mem_vec_6243 ,mem_vec_6244 ,mem_vec_6245 ,mem_vec_6246 ,mem_vec_6247 ,mem_vec_6248 ,mem_vec_6249 ,mem_vec_6250 ,mem_vec_6251 ,mem_vec_6252 ,mem_vec_6253 ,mem_vec_6254 ,mem_vec_6255 ,mem_vec_6256 ,mem_vec_6257 ,mem_vec_6258 ,mem_vec_6259 ,mem_vec_6260 ,mem_vec_6261 ,mem_vec_6262 ,mem_vec_6263 ,mem_vec_6264 ,mem_vec_6265 ,mem_vec_6266 ,mem_vec_6267 ,mem_vec_6268 ,mem_vec_6269 ,mem_vec_6270 ,mem_vec_6271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y433 = 0;
y433_p_0 = 0;
x589 = 0;
x589_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
x588 = 0;
x588_p_1 = 0;
c441 = 0;
c441_p_0 = 0;
							for (x = x588, xp_2 = x588_p_1, xp_1 = x588_p_0, xp_0 = 0;x < x588 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6228 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6229 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6230 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6231 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6232 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6233 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6234 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6235 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6236 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6237 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6238 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_6239 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_6240 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_6241 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_6242 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_6243 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_6244 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_6245 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_6246 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_6247 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c441, cp_1 = c441_p_0, cp_0 = 0;c < c441 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6228);
											mem_vec_6228 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6229);
											mem_vec_6229 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6230);
											mem_vec_6230 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6231);
											mem_vec_6231 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6232);
											mem_vec_6232 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6233);
											mem_vec_6233 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6234);
											mem_vec_6234 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6235);
											mem_vec_6235 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6236);
											mem_vec_6236 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6237);
											mem_vec_6237 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6238);
											mem_vec_6238 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6239);
											mem_vec_6239 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6240);
											mem_vec_6240 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6241);
											mem_vec_6241 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6242);
											mem_vec_6242 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6243);
											mem_vec_6243 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6244);
											mem_vec_6244 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6245);
											mem_vec_6245 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6246);
											mem_vec_6246 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6247);
											mem_vec_6247 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6228);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6229);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6230);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6231);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6232);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6233);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6234);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6235);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6236);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6237);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6238);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6239);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6240);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6241);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6242);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6243);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6244);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6245);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_6246);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_6247);
							}
}
