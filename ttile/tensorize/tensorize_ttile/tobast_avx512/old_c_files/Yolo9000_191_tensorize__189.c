
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (16, c)]
*/
IND_TYPE c, cp_0, c1288_p_0, c1289_p_0, cp_1, c1288_p_1, cp_2, c1288, c1289, f, fp_0, x, xp_0, x966_p_0, xp_1, x966, y, yp_0;
IND_TYPE y644 = 0;
IND_TYPE x967 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1290 = 0;
IND_TYPE f644 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_10992 ,mem_vec_10993 ,mem_vec_10994 ,mem_vec_10995 ,mem_vec_10996 ,mem_vec_10997 ,mem_vec_10998 ,mem_vec_10999 ,mem_vec_11000 ,mem_vec_11001 ,mem_vec_11002 ,mem_vec_11003 ,mem_vec_11004 ,mem_vec_11005 ,mem_vec_11006 ,mem_vec_11007 ,mem_vec_11008 ,mem_vec_11009 ,mem_vec_11010 ,mem_vec_11011 ,mem_vec_11012 ,mem_vec_11013 ,mem_vec_11014 ,mem_vec_11015 ,mem_vec_11016 ,mem_vec_11017 ,mem_vec_11018 ,mem_vec_11019 ,mem_vec_11020 ,mem_vec_11021 ,mem_vec_11022 ,mem_vec_11023 ,mem_vec_11024 ,mem_vec_11025 ,mem_vec_11026 ,mem_vec_11027 ,mem_vec_11028 ,mem_vec_11029 ,mem_vec_11030 ,mem_vec_11031 ,mem_vec_11032 ,mem_vec_11033 ,mem_vec_11034 ,mem_vec_11035 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 16) (1024 / 64)
c1289 = 0;
c1289_p_0 = 0;
y = 0;
yp_0 = 0;
x966 = 0;
x966_p_0 = 0;
f = 0;
fp_0 = 0;
c1288 = 0;
c1288_p_1 = 0;
						for (x = x966, xp_1 = x966_p_0, xp_0 = 0;x < x966 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10992 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_10993 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_10994 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_10995 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_10996 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_10997 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_10998 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_10999 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_11000 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_11001 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_11002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_11003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_11004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_11005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_11006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_11007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_11008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_11009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_11010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_11011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c1288, cp_2 = c1288_p_1, cp_1 = c1288_p_0, cp_0 = 0;c < c1288 + 16;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10992);
										mem_vec_10992 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10993);
										mem_vec_10993 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10994);
										mem_vec_10994 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10995);
										mem_vec_10995 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10996);
										mem_vec_10996 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10997);
										mem_vec_10997 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10998);
										mem_vec_10998 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10999);
										mem_vec_10999 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11000);
										mem_vec_11000 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11001);
										mem_vec_11001 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11002);
										mem_vec_11002 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11003);
										mem_vec_11003 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11004);
										mem_vec_11004 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11005);
										mem_vec_11005 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11006);
										mem_vec_11006 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11007);
										mem_vec_11007 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11008);
										mem_vec_11008 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11009);
										mem_vec_11009 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11010);
										mem_vec_11010 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11011);
										mem_vec_11011 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_10992);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_10993);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_10994);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_10995);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_10996);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_10997);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_10998);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_10999);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_11000);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_11001);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_11002);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_11003);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_11004);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_11005);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_11006);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_11007);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_11008);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_11009);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_11010);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_11011);
						}
}
