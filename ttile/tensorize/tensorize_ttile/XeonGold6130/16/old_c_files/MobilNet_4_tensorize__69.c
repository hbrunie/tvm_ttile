
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); U (14, y); T (64, c); Hoist_vars [c]; T (3, h); T (4, x);
  T (3, w); T (2, c); T (2, f); T (7, x); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c402_p_0, cp_1, c402, f, fp_0, f402_p_0, fp_1, f402, h, hp_0, w, wp_0, x, xp_0, x374_p_0, xp_1, x374, y, yp_0;
IND_TYPE y268 = 0;
IND_TYPE x375 = 0;
IND_TYPE h225 = 0;
IND_TYPE w230 = 0;
IND_TYPE c403 = 0;
IND_TYPE f403 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3924 ,mem_vec_3925 ,mem_vec_3926 ,mem_vec_3927 ,mem_vec_3928 ,mem_vec_3929 ,mem_vec_3930 ,mem_vec_3931 ,mem_vec_3932 ,mem_vec_3933 ,mem_vec_3934 ,mem_vec_3935 ,mem_vec_3936 ,mem_vec_3937 ,mem_vec_3938 ,mem_vec_3939 ,mem_vec_3940 ,mem_vec_3941 ,mem_vec_3942 ,mem_vec_3943 ,mem_vec_3944 ,mem_vec_3945 ,mem_vec_3946 ,mem_vec_3947 ,mem_vec_3948 ,mem_vec_3949 ,mem_vec_3950 ,mem_vec_3951 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
f402 = 0;
f402_p_0 = 0;
y = 0;
yp_0 = 0;
x374 = 0;
x374_p_0 = 0;
f = 0;
fp_1 = 0;
c402 = 0;
c402_p_0 = 0;
					for (w = w230, wp_0 = 0;w < w230 + 3;w += 1, wp_0 += 1){
						// y = 14, x = 4, h = 3, w = 1, c = 64, f = 32
						// T (x, 4) (4 / 1)
						for (x = x374, xp_1 = x374_p_0, xp_0 = 0;x < x374 + 4;x += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h225, hp_0 = 0;h < h225 + 3;h += 1, hp_0 += 1){
										mem_vec_3924 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_3925 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_3926 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_3927 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_3928 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_3929 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_3930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_3931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_3932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_3933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_3934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_3935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_3936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_3937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_3938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_3939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_3940 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_3941 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_3942 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_3943 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_3944 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_3945 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_3946 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_3947 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										mem_vec_3948 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										mem_vec_3949 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
										mem_vec_3950 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
										mem_vec_3951 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c402, cp_1 = c402_p_0, cp_0 = 0;c < c402 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3924);
											mem_vec_3924 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3925);
											mem_vec_3925 = vec_3;
											scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3926);
											mem_vec_3926 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3927);
											mem_vec_3927 = vec_7;
											scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3928);
											mem_vec_3928 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3929);
											mem_vec_3929 = vec_10;
											scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3930);
											mem_vec_3930 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3931);
											mem_vec_3931 = vec_13;
											scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3932);
											mem_vec_3932 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3933);
											mem_vec_3933 = vec_16;
											scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3934);
											mem_vec_3934 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3935);
											mem_vec_3935 = vec_19;
											scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3936);
											mem_vec_3936 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3937);
											mem_vec_3937 = vec_22;
											scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3938);
											mem_vec_3938 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3939);
											mem_vec_3939 = vec_25;
											scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3940);
											mem_vec_3940 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3941);
											mem_vec_3941 = vec_28;
											scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3942);
											mem_vec_3942 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3943);
											mem_vec_3943 = vec_31;
											scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3944);
											mem_vec_3944 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3945);
											mem_vec_3945 = vec_34;
											scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3946);
											mem_vec_3946 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3947);
											mem_vec_3947 = vec_37;
											scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3948);
											mem_vec_3948 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3949);
											mem_vec_3949 = vec_40;
											scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);
											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3950);
											mem_vec_3950 = vec_41;
											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3951);
											mem_vec_3951 = vec_43;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3924);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3925);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3926);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3927);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3928);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3929);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_3930);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_3931);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_3932);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_3933);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_3934);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_3935);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_3936);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_3937);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_3938);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_3939);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_3940);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_3941);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_3942);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_3943);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_3944);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_3945);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_3946);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_3947);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_3948);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_3949);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_3950);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_3951);
							}
						}
					}
}
