
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (34, x); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))];
  T (8, f); T (1, x); T (2, y)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, x, xp_0, x368_p_0, x369_p_0, xp_1, x368_p_1, xp_2, x368, x369, y, yp_0, y268_p_0, yp_1, y268;
IND_TYPE y269 = 0;
IND_TYPE x370 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c277 = 0;
IND_TYPE f184 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4064 ,mem_vec_4065 ,mem_vec_4066 ,mem_vec_4067 ,mem_vec_4068 ,mem_vec_4069 ,mem_vec_4070 ,mem_vec_4071 ,mem_vec_4072 ,mem_vec_4073 ,mem_vec_4074 ,mem_vec_4075 ,mem_vec_4076 ,mem_vec_4077 ,mem_vec_4078 ,mem_vec_4079 ,mem_vec_4080 ,mem_vec_4081 ,mem_vec_4082 ,mem_vec_4083 ,mem_vec_4084 ,mem_vec_4085 ,mem_vec_4086 ,mem_vec_4087 ,mem_vec_4088 ,mem_vec_4089 ,mem_vec_4090 ,mem_vec_4091 ,mem_vec_4092 ,mem_vec_4093 ,mem_vec_4094 ,mem_vec_4095 ,mem_vec_4096 ,mem_vec_4097 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (y, 2) (34 / 17)
y268 = 0;
y268_p_0 = 0;
x369 = 0;
x369_p_0 = 0;
		for (f = f184, fp_0 = 0;f < f184 + 256;f += 32, fp_0 += 32){
				for (y = y268, yp_1 = y268_p_0, yp_0 = 0;y < y268 + 8;y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 34) (34 / 1)
					for (x368 = x369, x368_p_1 = x369_p_0, x368_p_0 = 0;x368 < x369 + 34;x368 += 1, x368_p_1 += 1, x368_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c276 = c277, c276_p_0 = 0;c276 < c277 + 512;c276 += 512, c276_p_0 += 512){
							// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
							// T (x, 1) (1 / 1)
							for (x = x368, xp_2 = x368_p_1, xp_1 = x368_p_0, xp_0 = 0;x < x368 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4064 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4065 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4066 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4067 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4068 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4069 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4070 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4071 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4072 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4073 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4074 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4075 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4076 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4077 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4078 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4079 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 512;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4064);
											mem_vec_4064 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4065);
											mem_vec_4065 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4066);
											mem_vec_4066 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4067);
											mem_vec_4067 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4068);
											mem_vec_4068 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4069);
											mem_vec_4069 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4070);
											mem_vec_4070 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4071);
											mem_vec_4071 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4072);
											mem_vec_4072 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4073);
											mem_vec_4073 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4074);
											mem_vec_4074 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4075);
											mem_vec_4075 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4076);
											mem_vec_4076 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4077);
											mem_vec_4077 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4078);
											mem_vec_4078 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4079);
											mem_vec_4079 = vec_25;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4064);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4065);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4066);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4067);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4068);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4069);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4070);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4071);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4072);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4073);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4074);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4075);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4076);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4077);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4078);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4079);
							}
						}
					}
				}
				for (y = y268 + 8, yp_1 = y268_p_0, yp_0 = 0;y < y268 + 8 + 9;y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 34) (34 / 1)
					for (x368 = x369, x368_p_1 = x369_p_0, x368_p_0 = 0;x368 < x369 + 34;x368 += 1, x368_p_1 += 1, x368_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
						// T (c, 1) (512 / 512)
						for (c276 = c277, c276_p_0 = 0;c276 < c277 + 512;c276 += 512, c276_p_0 += 512){
							// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
							// T (x, 1) (1 / 1)
							for (x = x368, xp_2 = x368_p_1, xp_1 = x368_p_0, xp_0 = 0;x < x368 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4080 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4081 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4082 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4083 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4084 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4085 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4086 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4087 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4088 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4089 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4090 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4091 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4092 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4093 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4094 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4095 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_4096 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4097 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
										// T (c, 512) (512 / 1)
										for (c = c276, cp_1 = c276_p_0, cp_0 = 0;c < c276 + 512;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4080);
											mem_vec_4080 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4081);
											mem_vec_4081 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4082);
											mem_vec_4082 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4083);
											mem_vec_4083 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4084);
											mem_vec_4084 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4085);
											mem_vec_4085 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4086);
											mem_vec_4086 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4087);
											mem_vec_4087 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4088);
											mem_vec_4088 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4089);
											mem_vec_4089 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4090);
											mem_vec_4090 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4091);
											mem_vec_4091 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4092);
											mem_vec_4092 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4093);
											mem_vec_4093 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4094);
											mem_vec_4094 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4095);
											mem_vec_4095 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4096);
											mem_vec_4096 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4097);
											mem_vec_4097 = vec_28;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4080);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4081);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4082);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4083);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4084);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4085);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4086);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4087);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4088);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4089);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4090);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4091);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4092);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4093);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4094);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4095);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4096);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4097);
							}
						}
					}
				}
		}
}
