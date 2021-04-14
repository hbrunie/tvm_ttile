
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, f);
  T (1, c); T (1, f)]
*/
IND_TYPE c, cp_0, c480_p_0, cp_1, c480, f, fp_0, f640_p_0, f641_p_0, fp_1, f640_p_1, fp_2, f640, f641, h, hp_0, w, wp_0, x, xp_0, x480_p_0, xp_1, x480, y, yp_0;
IND_TYPE y320 = 0;
IND_TYPE x481 = 0;
IND_TYPE h320 = 0;
IND_TYPE w320 = 0;
IND_TYPE c481 = 0;
IND_TYPE f642 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_6976 ,mem_vec_6977 ,mem_vec_6978 ,mem_vec_6979 ,mem_vec_6980 ,mem_vec_6981 ,mem_vec_6982 ,mem_vec_6983 ,mem_vec_6984 ,mem_vec_6985 ,mem_vec_6986 ,mem_vec_6987 ,mem_vec_6988 ,mem_vec_6989 ,mem_vec_6990 ,mem_vec_6991 ,mem_vec_6992 ,mem_vec_6993 ,mem_vec_6994 ,mem_vec_6995 ,mem_vec_6996 ,mem_vec_6997 ,mem_vec_6998 ,mem_vec_6999 ,mem_vec_7000 ,mem_vec_7001 ,mem_vec_7002 ,mem_vec_7003 ,mem_vec_7004 ,mem_vec_7005 ,mem_vec_7006 ,mem_vec_7007 ,mem_vec_7008 ,mem_vec_7009 ,mem_vec_7010 ,mem_vec_7011 ,mem_vec_7012 ,mem_vec_7013 ,mem_vec_7014 ,mem_vec_7015 ,mem_vec_7016 ,mem_vec_7017 ,mem_vec_7018 ,mem_vec_7019 ,mem_vec_7020 ,mem_vec_7021 ,mem_vec_7022 ,mem_vec_7023 ,mem_vec_7024 ,mem_vec_7025 ,mem_vec_7026 ,mem_vec_7027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
f641 = 0;
f641_p_0 = 0;
c480 = 0;
c480_p_0 = 0;
f640 = 0;
f640_p_1 = 0;
y = 0;
yp_0 = 0;
x480 = 0;
x480_p_0 = 0;
f = 0;
fp_2 = 0;
							for (h = h320, hp_0 = 0;h < h320 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (w, 3) (3 / 1)
								for (w = w320, wp_0 = 0;w < w320 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
									// T (x, 34) (34 / 1)
									for (x = x480, xp_1 = x480_p_0, xp_0 = 0;x < x480 + 34;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6976 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_6977 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_6978 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
												mem_vec_6979 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
												mem_vec_6980 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_6981 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_6982 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
												mem_vec_6983 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
												mem_vec_6984 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_6985 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_6986 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
												mem_vec_6987 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
												mem_vec_6988 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_6989 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_6990 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
												mem_vec_6991 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
												mem_vec_6992 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_6993 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_6994 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
												mem_vec_6995 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
												mem_vec_6996 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_6997 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_6998 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
												mem_vec_6999 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
												// T (c, 256) (256 / 1)
												for (c = c480, cp_1 = c480_p_0, cp_0 = 0;c < c480 + 256;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6976);
													mem_vec_6976 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6977);
													mem_vec_6977 = vec_3;
													vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6978);
													mem_vec_6978 = vec_5;
													vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6979);
													mem_vec_6979 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6980);
													mem_vec_6980 = vec_9;
													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6981);
													mem_vec_6981 = vec_11;
													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6982);
													mem_vec_6982 = vec_12;
													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6983);
													mem_vec_6983 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6984);
													mem_vec_6984 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6985);
													mem_vec_6985 = vec_16;
													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6986);
													mem_vec_6986 = vec_17;
													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6987);
													mem_vec_6987 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6988);
													mem_vec_6988 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6989);
													mem_vec_6989 = vec_21;
													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6990);
													mem_vec_6990 = vec_22;
													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6991);
													mem_vec_6991 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);
													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6992);
													mem_vec_6992 = vec_24;
													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6993);
													mem_vec_6993 = vec_26;
													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6994);
													mem_vec_6994 = vec_27;
													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6995);
													mem_vec_6995 = vec_28;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6996);
													mem_vec_6996 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6997);
													mem_vec_6997 = vec_31;
													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6998);
													mem_vec_6998 = vec_32;
													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6999);
													mem_vec_6999 = vec_33;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6976);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6977);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_6978);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_6979);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6980);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6981);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_6982);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_6983);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6984);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6985);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_6986);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_6987);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6988);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6989);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_6990);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_6991);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6992);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6993);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_6994);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_6995);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6996);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6997);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_6998);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_6999);
									}
								}
							}
}
