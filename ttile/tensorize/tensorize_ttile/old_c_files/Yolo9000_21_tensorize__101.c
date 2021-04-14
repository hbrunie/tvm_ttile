
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (1, c); T (17, x); T (16, x)]
*/
IND_TYPE c, cp_0, c1098_p_0, cp_1, c1098, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1830_p_0, x1831_p_0, x1832_p_0, xp_1, x1830_p_1, x1831_p_1, xp_2, x1830_p_2, xp_3, x1830, x1831, x1832, y, yp_0;
IND_TYPE y732 = 0;
IND_TYPE x1833 = 0;
IND_TYPE h732 = 0;
IND_TYPE w592 = 0;
IND_TYPE c1099 = 0;
IND_TYPE f592 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8964 ,mem_vec_8965 ,mem_vec_8966 ,mem_vec_8967 ,mem_vec_8968 ,mem_vec_8969 ,mem_vec_8970 ,mem_vec_8971 ,mem_vec_8972 ,mem_vec_8973 ,mem_vec_8974 ,mem_vec_8975 ,mem_vec_8976 ,mem_vec_8977 ,mem_vec_8978 ,mem_vec_8979 ,mem_vec_8980 ,mem_vec_8981 ,mem_vec_8982 ,mem_vec_8983 ,mem_vec_8984 ,mem_vec_8985 ,mem_vec_8986 ,mem_vec_8987 ,mem_vec_8988 ,mem_vec_8989 ,mem_vec_8990 ,mem_vec_8991 ,mem_vec_8992 ,mem_vec_8993 ,mem_vec_8994 ,mem_vec_8995 ,mem_vec_8996 ,mem_vec_8997 ,mem_vec_8998 ,mem_vec_8999 ,mem_vec_9000 ,mem_vec_9001 ,mem_vec_9002 ,mem_vec_9003 ,mem_vec_9004 ,mem_vec_9005 ,mem_vec_9006 ,mem_vec_9007 ,mem_vec_9008 ,mem_vec_9009 ,mem_vec_9010 ,mem_vec_9011 ,mem_vec_9012 ,mem_vec_9013 ,mem_vec_9014 ,mem_vec_9015 ,mem_vec_9016 ,mem_vec_9017 ,mem_vec_9018 ,mem_vec_9019 ,mem_vec_9020 ,mem_vec_9021 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 16) (272 / 17)
x1832 = 0;
x1832_p_0 = 0;
x1831 = 0;
x1831_p_1 = 0;
c1098 = 0;
c1098_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1830 = 0;
x1830_p_2 = 0;
							for (h = h732, hp_0 = 0;h < h732 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w592, wp_0 = 0;w < w592 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1830, xp_3 = x1830_p_2, xp_2 = x1830_p_1, xp_1 = x1830_p_0, xp_0 = 0;x < x1830 + 1;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8964 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_8965 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_8966 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_8967 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_8968 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_8969 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_8970 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_8971 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_8972 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_8973 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_8974 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_8975 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_8976 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_8977 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_8978 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_8979 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_8980 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_8981 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_8982 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_8983 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_8984 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_8985 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_8986 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_8987 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_8988 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_8989 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												mem_vec_8990 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
												mem_vec_8991 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;c < c1098 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8964);
													mem_vec_8964 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8965);
													mem_vec_8965 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8966);
													mem_vec_8966 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8967);
													mem_vec_8967 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8968);
													mem_vec_8968 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8969);
													mem_vec_8969 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8970);
													mem_vec_8970 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8971);
													mem_vec_8971 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8972);
													mem_vec_8972 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8973);
													mem_vec_8973 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8974);
													mem_vec_8974 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8975);
													mem_vec_8975 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8976);
													mem_vec_8976 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8977);
													mem_vec_8977 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8978);
													mem_vec_8978 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8979);
													mem_vec_8979 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8980);
													mem_vec_8980 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8981);
													mem_vec_8981 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8982);
													mem_vec_8982 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8983);
													mem_vec_8983 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8984);
													mem_vec_8984 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8985);
													mem_vec_8985 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8986);
													mem_vec_8986 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8987);
													mem_vec_8987 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8988);
													mem_vec_8988 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8989);
													mem_vec_8989 = vec_40;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);
													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8990);
													mem_vec_8990 = vec_41;
													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8991);
													mem_vec_8991 = vec_43;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8964);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8965);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8966);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8967);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8968);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8969);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8970);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8971);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8972);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8973);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8974);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8975);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8976);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8977);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8978);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8979);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8980);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8981);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8982);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_8983);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_8984);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_8985);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_8986);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_8987);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_8988);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_8989);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_8990);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_8991);
									}
								}
							}
}
