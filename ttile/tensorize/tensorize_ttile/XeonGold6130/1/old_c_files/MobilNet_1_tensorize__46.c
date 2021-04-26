
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (1, c); T (3, w); T (112, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (2, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c540_p_0, cp_1, c540, f, fp_0, w, wp_0, x, xp_0, x484_p_0, xp_1, x484, y, yp_0, y540_p_0, yp_1, y540;
IND_TYPE y541 = 0;
IND_TYPE x485 = 0;
IND_TYPE h = 0;
IND_TYPE w360 = 0;
IND_TYPE c541 = 0;
IND_TYPE f304 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4320 ,mem_vec_4321 ,mem_vec_4322 ,mem_vec_4323 ,mem_vec_4324 ,mem_vec_4325 ,mem_vec_4326 ,mem_vec_4327 ,mem_vec_4328 ,mem_vec_4329 ,mem_vec_4330 ,mem_vec_4331 ,mem_vec_4332 ,mem_vec_4333 ,mem_vec_4334 ,mem_vec_4335 ,mem_vec_4336 ,mem_vec_4337 ,mem_vec_4338 ,mem_vec_4339 ,mem_vec_4340 ,mem_vec_4341 ,mem_vec_4342 ,mem_vec_4343 ,mem_vec_4344 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 1) (112 / 112)
y540 = 0;
y540_p_0 = 0;
	for (f = f304, fp_0 = 0;f < f304 + 32;f += 16, fp_0 += 16){
			for (y = y540, yp_1 = y540_p_0, yp_0 = 0;y < y540 + 60;y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 16
				// T (x, 112) (112 / 1)
				for (x484 = x485, x484_p_0 = 0;x484 < x485 + 112;x484 += 1, x484_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w360, wp_0 = 0;w < w360 + 3;w += 1, wp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
						// T (c, 1) (32 / 32)
						for (c540 = c541, c540_p_0 = 0;c540 < c541 + 32;c540 += 32, c540_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
							// T (x, 1) (1 / 1)
							for (x = x484, xp_1 = x484_p_0, xp_0 = 0;x < x484 + 1;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4320 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4321 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4322 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4323 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4324 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4325 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4326 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4327 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4328 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4329 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4330 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4331 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;c < c540 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4320);
											mem_vec_4320 = vec_0;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4321);
											mem_vec_4321 = vec_3;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4322);
											mem_vec_4322 = vec_5;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4323);
											mem_vec_4323 = vec_7;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4324);
											mem_vec_4324 = vec_9;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4325);
											mem_vec_4325 = vec_11;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_4326);
											mem_vec_4326 = vec_13;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_4327);
											mem_vec_4327 = vec_15;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4328);
											mem_vec_4328 = vec_17;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4329);
											mem_vec_4329 = vec_19;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);
											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_4330);
											mem_vec_4330 = vec_21;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4331);
											mem_vec_4331 = vec_23;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_26 = _mm512_set1_ps(scal_12);
											vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_4320);
											mem_vec_4320 = vec_25;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4321);
											mem_vec_4321 = vec_28;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_4322);
											mem_vec_4322 = vec_30;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_4323);
											mem_vec_4323 = vec_32;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_4324);
											mem_vec_4324 = vec_34;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);
											vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_4325);
											mem_vec_4325 = vec_36;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_4326);
											mem_vec_4326 = vec_38;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_4327);
											mem_vec_4327 = vec_40;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);
											vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_4328);
											mem_vec_4328 = vec_42;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);
											vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_4329);
											mem_vec_4329 = vec_44;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_4330);
											mem_vec_4330 = vec_46;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_4331);
											mem_vec_4331 = vec_48;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_51 = _mm512_set1_ps(scal_24);
											vec_52 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_4320);
											mem_vec_4320 = vec_50;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_4321);
											mem_vec_4321 = vec_53;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_4322);
											mem_vec_4322 = vec_55;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_4323);
											mem_vec_4323 = vec_57;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);
											vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_4324);
											mem_vec_4324 = vec_59;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_4325);
											mem_vec_4325 = vec_61;
											scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_4326);
											mem_vec_4326 = vec_63;
											scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);
											vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_4327);
											mem_vec_4327 = vec_65;
											scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_4328);
											mem_vec_4328 = vec_67;
											scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_4329);
											mem_vec_4329 = vec_69;
											scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);
											vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_4330);
											mem_vec_4330 = vec_71;
											scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);
											vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_4331);
											mem_vec_4331 = vec_73;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4320);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4321);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4322);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4323);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4324);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4325);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4326);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4327);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4328);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4329);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4330);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4331);
							}
						}
					}
				}
			}
			for (y = y540 + 60, yp_1 = y540_p_0, yp_0 = 0;y < y540 + 60 + 52;y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 16
				// T (x, 112) (112 / 1)
				for (x484 = x485, x484_p_0 = 0;x484 < x485 + 112;x484 += 1, x484_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w360, wp_0 = 0;w < w360 + 3;w += 1, wp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
						// T (c, 1) (32 / 32)
						for (c540 = c541, c540_p_0 = 0;c540 < c541 + 32;c540 += 32, c540_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
							// T (x, 1) (1 / 1)
							for (x = x484, xp_1 = x484_p_0, xp_0 = 0;x < x484 + 1;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4332 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4333 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4334 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4335 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4336 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4337 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4338 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4339 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4340 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4341 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4342 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4343 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_4344 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
										// T (c, 32) (32 / 1)
										for (c = c540, cp_1 = c540_p_0, cp_0 = 0;c < c540 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4332);
											mem_vec_4332 = vec_0;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4333);
											mem_vec_4333 = vec_3;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4334);
											mem_vec_4334 = vec_5;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4335);
											mem_vec_4335 = vec_7;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4336);
											mem_vec_4336 = vec_9;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4337);
											mem_vec_4337 = vec_11;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_4338);
											mem_vec_4338 = vec_13;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_4339);
											mem_vec_4339 = vec_15;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4340);
											mem_vec_4340 = vec_17;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4341);
											mem_vec_4341 = vec_19;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);
											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_4342);
											mem_vec_4342 = vec_21;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4343);
											mem_vec_4343 = vec_23;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
											vec_26 = _mm512_set1_ps(scal_12);
											vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_4344);
											mem_vec_4344 = vec_25;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_28 = _mm512_set1_ps(scal_13);
											vec_29 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_4332);
											mem_vec_4332 = vec_27;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_4333);
											mem_vec_4333 = vec_30;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_4334);
											mem_vec_4334 = vec_32;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_4335);
											mem_vec_4335 = vec_34;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);
											vec_36 = _mm512_fmadd_ps(vec_37, vec_29, mem_vec_4336);
											mem_vec_4336 = vec_36;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_29, mem_vec_4337);
											mem_vec_4337 = vec_38;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_29, mem_vec_4338);
											mem_vec_4338 = vec_40;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);
											vec_42 = _mm512_fmadd_ps(vec_43, vec_29, mem_vec_4339);
											mem_vec_4339 = vec_42;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);
											vec_44 = _mm512_fmadd_ps(vec_45, vec_29, mem_vec_4340);
											mem_vec_4340 = vec_44;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_29, mem_vec_4341);
											mem_vec_4341 = vec_46;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_29, mem_vec_4342);
											mem_vec_4342 = vec_48;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
											vec_51 = _mm512_set1_ps(scal_24);
											vec_50 = _mm512_fmadd_ps(vec_51, vec_29, mem_vec_4343);
											mem_vec_4343 = vec_50;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_25);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_29, mem_vec_4344);
											mem_vec_4344 = vec_52;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_26);
											vec_56 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_4332);
											mem_vec_4332 = vec_54;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_4333);
											mem_vec_4333 = vec_57;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);
											vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_4334);
											mem_vec_4334 = vec_59;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_4335);
											mem_vec_4335 = vec_61;
											scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_4336);
											mem_vec_4336 = vec_63;
											scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);
											vec_65 = _mm512_fmadd_ps(vec_66, vec_56, mem_vec_4337);
											mem_vec_4337 = vec_65;
											scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_4338);
											mem_vec_4338 = vec_67;
											scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_4339);
											mem_vec_4339 = vec_69;
											scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);
											vec_71 = _mm512_fmadd_ps(vec_72, vec_56, mem_vec_4340);
											mem_vec_4340 = vec_71;
											scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);
											vec_73 = _mm512_fmadd_ps(vec_74, vec_56, mem_vec_4341);
											mem_vec_4341 = vec_73;
											scal_36 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_36);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_4342);
											mem_vec_4342 = vec_75;
											scal_37 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_37);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_56, mem_vec_4343);
											mem_vec_4343 = vec_77;
											scal_38 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h + 2) + c];
											vec_80 = _mm512_set1_ps(scal_38);
											vec_79 = _mm512_fmadd_ps(vec_80, vec_56, mem_vec_4344);
											mem_vec_4344 = vec_79;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4332);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4333);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4334);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4335);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4336);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4337);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4338);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4339);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4340);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4341);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4342);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4343);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4344);
							}
						}
					}
				}
			}
	}
}
