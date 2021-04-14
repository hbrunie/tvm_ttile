void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (2, f);
  T (16, c); T (4, x)]
*/
IND_TYPE c, cp_0, c494_p_0, cp_1, c494, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x514_p_0, x515_p_0, xp_1, x514_p_1, xp_2, x514, x515, y, yp_0;
IND_TYPE y288 = 0;
IND_TYPE x516 = 0;
IND_TYPE h252 = 0;
IND_TYPE w264 = 0;
IND_TYPE c495 = 0;
IND_TYPE f226 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3944 ,mem_vec_3945 ,mem_vec_3946 ,mem_vec_3947 ,mem_vec_3948 ,mem_vec_3949 ,mem_vec_3950 ,mem_vec_3951 ,mem_vec_3952 ,mem_vec_3953 ,mem_vec_3954 ,mem_vec_3955 ,mem_vec_3956 ,mem_vec_3957 ,mem_vec_3958 ,mem_vec_3959 ,mem_vec_3960 ,mem_vec_3961 ,mem_vec_3962 ,mem_vec_3963 ,mem_vec_3964 ,mem_vec_3965 ,mem_vec_3966 ,mem_vec_3967 ,mem_vec_3968 ,mem_vec_3969 ,mem_vec_3970 ,mem_vec_3971 ,mem_vec_3972 ,mem_vec_3973 ,mem_vec_3974 ,mem_vec_3975 ,mem_vec_3976 ,mem_vec_3977 ,mem_vec_3978 ,mem_vec_3979 ,mem_vec_3980 ,mem_vec_3981 ,mem_vec_3982 ,mem_vec_3983 ,mem_vec_3984 ,mem_vec_3985 ,mem_vec_3986 ,mem_vec_3987 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
x515 = 0;
x515_p_0 = 0;
c494 = 0;
c494_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x514 = 0;
x514_p_1 = 0;
						for (h = h252, hp_0 = 0;h < h252 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w264, wp_0 = 0;w < w264 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 4, f = 32
								// T (x, 7) (7 / 1)
								for (x = x514, xp_2 = x514_p_1, xp_1 = x514_p_0, xp_0 = 0;x < x514 + 7;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3964 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3965 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3966 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3967 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3968 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3969 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3970 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_3971 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_3972 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_3973 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_3974 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_3975 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_3976 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_3977 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_3978 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_3979 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_3980 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_3981 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_3982 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_3983 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_3984 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_3985 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_3986 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_3987 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c494, cp_1 = c494_p_0, cp_0 = 0;c < c494 + 4;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3964);
												mem_vec_3964 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3965);
												mem_vec_3965 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3966);
												mem_vec_3966 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3967);
												mem_vec_3967 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3968);
												mem_vec_3968 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3969);
												mem_vec_3969 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3970);
												mem_vec_3970 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3971);
												mem_vec_3971 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3972);
												mem_vec_3972 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3973);
												mem_vec_3973 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3974);
												mem_vec_3974 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3975);
												mem_vec_3975 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3976);
												mem_vec_3976 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3977);
												mem_vec_3977 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3978);
												mem_vec_3978 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3979);
												mem_vec_3979 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3980);
												mem_vec_3980 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3981);
												mem_vec_3981 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3982);
												mem_vec_3982 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3983);
												mem_vec_3983 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3984);
												mem_vec_3984 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3985);
												mem_vec_3985 = vec_34;
												scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3986);
												mem_vec_3986 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3987);
												mem_vec_3987 = vec_37;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3964);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3965);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3966);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3967);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3968);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3969);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3970);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3971);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3972);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3973);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3974);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3975);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3976);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3977);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3978);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3979);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3980);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3981);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3982);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3983);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_3984);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_3985);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_3986);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_3987);
								}
							}
						}
}
