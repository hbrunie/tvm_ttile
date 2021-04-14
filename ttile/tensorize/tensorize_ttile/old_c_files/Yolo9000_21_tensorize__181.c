
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (32, c); T (34, x); T (2, x)]
*/
IND_TYPE c, cp_0, c996_p_0, cp_1, c996, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1660_p_0, x1661_p_0, x1662_p_0, xp_1, x1660_p_1, x1661_p_1, xp_2, x1660_p_2, xp_3, x1660, x1661, x1662, y, yp_0;
IND_TYPE y664 = 0;
IND_TYPE x1663 = 0;
IND_TYPE h664 = 0;
IND_TYPE w524 = 0;
IND_TYPE c997 = 0;
IND_TYPE f524 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6992 ,mem_vec_6993 ,mem_vec_6994 ,mem_vec_6995 ,mem_vec_6996 ,mem_vec_6997 ,mem_vec_6998 ,mem_vec_6999 ,mem_vec_7000 ,mem_vec_7001 ,mem_vec_7002 ,mem_vec_7003 ,mem_vec_7004 ,mem_vec_7005 ,mem_vec_7006 ,mem_vec_7007 ,mem_vec_7008 ,mem_vec_7009 ,mem_vec_7010 ,mem_vec_7011 ,mem_vec_7012 ,mem_vec_7013 ,mem_vec_7014 ,mem_vec_7015 ,mem_vec_7016 ,mem_vec_7017 ,mem_vec_7018 ,mem_vec_7019 ,mem_vec_7020 ,mem_vec_7021 ,mem_vec_7022 ,mem_vec_7023 ,mem_vec_7024 ,mem_vec_7025 ,mem_vec_7026 ,mem_vec_7027 ,mem_vec_7028 ,mem_vec_7029 ,mem_vec_7030 ,mem_vec_7031 ,mem_vec_7032 ,mem_vec_7033 ,mem_vec_7034 ,mem_vec_7035 ,mem_vec_7036 ,mem_vec_7037 ,mem_vec_7038 ,mem_vec_7039 ,mem_vec_7040 ,mem_vec_7041 ,mem_vec_7042 ,mem_vec_7043 ,mem_vec_7044 ,mem_vec_7045 ,mem_vec_7046 ,mem_vec_7047 ,mem_vec_7048 ,mem_vec_7049 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
x1662 = 0;
x1662_p_0 = 0;
x1661 = 0;
x1661_p_1 = 0;
c996 = 0;
c996_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1660 = 0;
x1660_p_2 = 0;
							for (h = h664, hp_0 = 0;h < h664 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w524, wp_0 = 0;w < w524 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1660, xp_3 = x1660_p_2, xp_2 = x1660_p_1, xp_1 = x1660_p_0, xp_0 = 0;x < x1660 + 2;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6992 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_6993 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_6994 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_6995 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_6996 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_6997 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_6998 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_6999 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_7000 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_7001 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_7002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_7003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_7004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_7005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_7006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_7007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_7008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_7009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_7010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_7011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_7012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_7013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_7014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_7015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_7016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_7017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												mem_vec_7018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
												mem_vec_7019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c996, cp_1 = c996_p_0, cp_0 = 0;c < c996 + 1;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6992);
													mem_vec_6992 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6993);
													mem_vec_6993 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6994);
													mem_vec_6994 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6995);
													mem_vec_6995 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6996);
													mem_vec_6996 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6997);
													mem_vec_6997 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6998);
													mem_vec_6998 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6999);
													mem_vec_6999 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7000);
													mem_vec_7000 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7001);
													mem_vec_7001 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7002);
													mem_vec_7002 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7003);
													mem_vec_7003 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7004);
													mem_vec_7004 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7005);
													mem_vec_7005 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7006);
													mem_vec_7006 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7007);
													mem_vec_7007 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7008);
													mem_vec_7008 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7009);
													mem_vec_7009 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7010);
													mem_vec_7010 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7011);
													mem_vec_7011 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7012);
													mem_vec_7012 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7013);
													mem_vec_7013 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7014);
													mem_vec_7014 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7015);
													mem_vec_7015 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7016);
													mem_vec_7016 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7017);
													mem_vec_7017 = vec_40;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);
													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7018);
													mem_vec_7018 = vec_41;
													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7019);
													mem_vec_7019 = vec_43;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6992);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6993);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6994);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6995);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6996);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6997);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6998);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6999);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7000);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7001);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7002);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7003);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7004);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_7005);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7006);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_7007);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_7008);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_7009);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_7010);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_7011);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_7012);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_7013);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_7014);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_7015);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_7016);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_7017);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_7018);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_7019);
									}
								}
							}
}
