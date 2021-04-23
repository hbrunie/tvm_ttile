
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (2, y); T (1, c);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]]
*/
IND_TYPE c, cp_0, c75_p_0, cp_1, c75, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y75_p_0, yp_1, y75;
IND_TYPE y76 = 0;
IND_TYPE x50 = 0;
IND_TYPE h50 = 0;
IND_TYPE w50 = 0;
IND_TYPE c76 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,mem_vec_1008 ,mem_vec_1009 ,mem_vec_1010 ,mem_vec_1011 ,mem_vec_1012 ,mem_vec_1013 ,mem_vec_1014 ,mem_vec_1015 ,mem_vec_1016 ,mem_vec_1017 ,mem_vec_1018 ,mem_vec_1019 ,mem_vec_1020 ,mem_vec_1021 ,mem_vec_1022 ,mem_vec_1023 ,mem_vec_1024 ,mem_vec_1025 ,mem_vec_1026 ,mem_vec_1027 ,mem_vec_1028 ,mem_vec_1029 ,mem_vec_1030 ,mem_vec_1031 ,mem_vec_1032 ,mem_vec_1033 ,mem_vec_1034 ,mem_vec_1035 ,mem_vec_1036 ,mem_vec_1037 ,mem_vec_1038 ,mem_vec_1039 ,mem_vec_1040 ,mem_vec_1041 ,mem_vec_1042 ,mem_vec_1043 ,mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y75 = 0;
y75_p_0 = 0;
c75 = 0;
c75_p_0 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_0 = 0;
					for (h = h50, hp_0 = 0;h < h50 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w50, wp_0 = 0;w < w50 + 3;w += 1, wp_0 += 1){
									mem_vec_1002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_1003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_1004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_1005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_1006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_1007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_1008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_1009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_1010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_1011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_1012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_1013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_1014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_1015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_1016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_1017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
									mem_vec_1018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
									mem_vec_1019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
									mem_vec_1020 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
									mem_vec_1021 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
									mem_vec_1022 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
									mem_vec_1023 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c75, cp_1 = c75_p_0, cp_0 = 0;c < c75 + 32;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1002);
										mem_vec_1002 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1003);
										mem_vec_1003 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1004);
										mem_vec_1004 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1005);
										mem_vec_1005 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1006);
										mem_vec_1006 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1007);
										mem_vec_1007 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1008);
										mem_vec_1008 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1009);
										mem_vec_1009 = vec_13;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1010);
										mem_vec_1010 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1011);
										mem_vec_1011 = vec_16;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1012);
										mem_vec_1012 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1013);
										mem_vec_1013 = vec_19;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1014);
										mem_vec_1014 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1015);
										mem_vec_1015 = vec_22;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1016);
										mem_vec_1016 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1017);
										mem_vec_1017 = vec_25;
										scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1018);
										mem_vec_1018 = vec_26;
										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1019);
										mem_vec_1019 = vec_28;
										scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1020);
										mem_vec_1020 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1021);
										mem_vec_1021 = vec_31;
										scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);
										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1022);
										mem_vec_1022 = vec_32;
										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1023);
										mem_vec_1023 = vec_34;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1002);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1003);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1004);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1005);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1006);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1007);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1008);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1009);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1010);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1011);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1012);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1013);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_1014);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_1015);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_1016);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_1017);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_1018);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_1019);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_1020);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_1021);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_1022);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_1023);
						}
					}
}
