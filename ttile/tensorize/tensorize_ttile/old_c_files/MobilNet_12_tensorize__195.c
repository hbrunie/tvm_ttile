void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 8)); ((Iter 4), (Arg 14))]; T (2, c);
  T (7, x)]
*/
IND_TYPE c, cp_0, c396_p_0, cp_1, c396, h, hp_0, w, wp_0, x, xp_0, x528_p_0, x529_p_0, xp_1, x528_p_1, xp_2, x528, x529, y, yp_0;
IND_TYPE y264 = 0;
IND_TYPE x530 = 0;
IND_TYPE h244 = 0;
IND_TYPE w264 = 0;
IND_TYPE c397 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3992 ,mem_vec_3993 ,mem_vec_3994 ,mem_vec_3995 ,mem_vec_3996 ,mem_vec_3997 ,mem_vec_3998 ,mem_vec_3999 ,mem_vec_4000 ,mem_vec_4001 ,mem_vec_4002 ,mem_vec_4003 ,mem_vec_4004 ,mem_vec_4005 ,mem_vec_4006 ,mem_vec_4007 ,mem_vec_4008 ,mem_vec_4009 ,mem_vec_4010 ,mem_vec_4011 ,mem_vec_4012 ,mem_vec_4013 ,mem_vec_4014 ,mem_vec_4015 ,mem_vec_4016 ,mem_vec_4017 ,mem_vec_4018 ,mem_vec_4019 ,mem_vec_4020 ,mem_vec_4021 ,mem_vec_4022 ,mem_vec_4023 ,mem_vec_4024 ,mem_vec_4025 ,mem_vec_4026 ,mem_vec_4027 ,mem_vec_4028 ,mem_vec_4029 ,mem_vec_4030 ,mem_vec_4031 ,mem_vec_4032 ,mem_vec_4033 ,mem_vec_4034 ,mem_vec_4035 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
x529 = 0;
x529_p_0 = 0;
c396 = 0;
c396_p_0 = 0;
y = 0;
yp_0 = 0;
x528 = 0;
x528_p_1 = 0;
					for (h = h244, hp_0 = 0;h < h244 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w264, wp_0 = 0;w < w264 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
							// T (x, 4) (4 / 1)
							for (x = x528, xp_2 = x528_p_1, xp_1 = x528_p_0, xp_0 = 0;x < x528 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4020 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4021 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4022 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4023 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_4024 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4025 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_4026 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4027 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_4028 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4029 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_4030 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_4031 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										mem_vec_4032 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										mem_vec_4033 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
										mem_vec_4034 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
										mem_vec_4035 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c396, cp_1 = c396_p_0, cp_0 = 0;c < c396 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4008);
											mem_vec_4008 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4009);
											mem_vec_4009 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4010);
											mem_vec_4010 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4011);
											mem_vec_4011 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4012);
											mem_vec_4012 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4013);
											mem_vec_4013 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4014);
											mem_vec_4014 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4015);
											mem_vec_4015 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4016);
											mem_vec_4016 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4017);
											mem_vec_4017 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4018);
											mem_vec_4018 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4019);
											mem_vec_4019 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4020);
											mem_vec_4020 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4021);
											mem_vec_4021 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4022);
											mem_vec_4022 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4023);
											mem_vec_4023 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4024);
											mem_vec_4024 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4025);
											mem_vec_4025 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4026);
											mem_vec_4026 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4027);
											mem_vec_4027 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4028);
											mem_vec_4028 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4029);
											mem_vec_4029 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4030);
											mem_vec_4030 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4031);
											mem_vec_4031 = vec_37;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4032);
											mem_vec_4032 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4033);
											mem_vec_4033 = vec_40;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);
											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_4034);
											mem_vec_4034 = vec_41;
											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_4035);
											mem_vec_4035 = vec_43;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4008);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4009);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4010);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4011);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4012);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4013);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4014);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4015);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4016);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4017);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4018);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4019);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4020);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4021);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4022);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4023);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4024);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4025);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4026);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4027);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4028);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4029);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4030);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_4031);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4032);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_4033);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_4034);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_4035);
							}
						}
					}
}
