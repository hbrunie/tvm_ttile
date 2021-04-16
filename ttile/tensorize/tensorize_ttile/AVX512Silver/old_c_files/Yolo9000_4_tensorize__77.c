
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (4, c); T (2, f); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (4, y)]
*/
IND_TYPE c, cp_0, c360_p_0, cp_1, c360, f, fp_0, w, wp_0, x, xp_0, x477_p_0, xp_1, x477, y, yp_0, y243_p_0, yp_1, y243;
IND_TYPE y244 = 0;
IND_TYPE x478 = 0;
IND_TYPE h = 0;
IND_TYPE w171 = 0;
IND_TYPE c361 = 0;
IND_TYPE f240 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5550 ,mem_vec_5551 ,mem_vec_5552 ,mem_vec_5553 ,mem_vec_5554 ,mem_vec_5555 ,mem_vec_5556 ,mem_vec_5557 ,mem_vec_5558 ,mem_vec_5559 ,mem_vec_5560 ,mem_vec_5561 ,mem_vec_5562 ,mem_vec_5563 ,mem_vec_5564 ,mem_vec_5565 ,mem_vec_5566 ,mem_vec_5567 ,mem_vec_5568 ,mem_vec_5569 ,mem_vec_5570 ,mem_vec_5571 ,mem_vec_5572 ,mem_vec_5573 ,mem_vec_5574 ,mem_vec_5575 ,mem_vec_5576 ,mem_vec_5577 ,mem_vec_5578 ,mem_vec_5579 ,mem_vec_5580 ,mem_vec_5581 ,mem_vec_5582 ,mem_vec_5583 ,mem_vec_5584 ,mem_vec_5585 ,mem_vec_5586 ,mem_vec_5587 ,mem_vec_5588 ,mem_vec_5589 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (y, 4) (136 / 34)
for (y243 = y244, y243_p_0 = 0;y243 < y244 + 136;y243 += 34, y243_p_0 += 34){
		for (y = y243, yp_1 = y243_p_0, yp_0 = 0;y < y243 + 4;y += 4, yp_1 += 4, yp_0 += 4){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x477 = x478, x477_p_0 = 0;x477 < x478 + 136;x477 += 34, x477_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f240, fp_0 = 0;f < f240 + 128;f += 64, fp_0 += 64){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c360 = c361, c360_p_0 = 0;c360 < c361 + 64;c360 += 16, c360_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w171, wp_0 = 0;w < w171 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x477, xp_1 = x477_p_0, xp_0 = 0;x < x477 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_5553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_5554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_5557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_5558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_5561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_5562 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5563 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5564 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_5565 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c360, cp_1 = c360_p_0, cp_0 = 0;c < c360 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5550);
											mem_vec_5550 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5551);
											mem_vec_5551 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5552);
											mem_vec_5552 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5553);
											mem_vec_5553 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5554);
											mem_vec_5554 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5555);
											mem_vec_5555 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5556);
											mem_vec_5556 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5557);
											mem_vec_5557 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5558);
											mem_vec_5558 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5559);
											mem_vec_5559 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5560);
											mem_vec_5560 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5561);
											mem_vec_5561 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5562);
											mem_vec_5562 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5563);
											mem_vec_5563 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5564);
											mem_vec_5564 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5565);
											mem_vec_5565 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_5550);
											mem_vec_5550 = vec_24;
											vec_28 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_5551);
											mem_vec_5551 = vec_27;
											vec_30 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_5552);
											mem_vec_5552 = vec_29;
											vec_32 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_5553);
											mem_vec_5553 = vec_31;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_34 = _mm512_set1_ps(scal_5);
											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_5554);
											mem_vec_5554 = vec_33;
											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_5555);
											mem_vec_5555 = vec_35;
											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5556);
											mem_vec_5556 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5557);
											mem_vec_5557 = vec_37;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_5558);
											mem_vec_5558 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_5559);
											mem_vec_5559 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_5560);
											mem_vec_5560 = vec_41;
											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_5561);
											mem_vec_5561 = vec_42;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_5562);
											mem_vec_5562 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5563);
											mem_vec_5563 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5564);
											mem_vec_5564 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_5565);
											mem_vec_5565 = vec_47;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_5550);
											mem_vec_5550 = vec_48;
											vec_52 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_5551);
											mem_vec_5551 = vec_51;
											vec_54 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_5552);
											mem_vec_5552 = vec_53;
											vec_56 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_5553);
											mem_vec_5553 = vec_55;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_9);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5554);
											mem_vec_5554 = vec_57;
											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_5555);
											mem_vec_5555 = vec_59;
											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5556);
											mem_vec_5556 = vec_60;
											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5557);
											mem_vec_5557 = vec_61;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_63 = _mm512_set1_ps(scal_10);
											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_5558);
											mem_vec_5558 = vec_62;
											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_5559);
											mem_vec_5559 = vec_64;
											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_5560);
											mem_vec_5560 = vec_65;
											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_5561);
											mem_vec_5561 = vec_66;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_5562);
											mem_vec_5562 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_5563);
											mem_vec_5563 = vec_69;
											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_5564);
											mem_vec_5564 = vec_70;
											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_5565);
											mem_vec_5565 = vec_71;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5550);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5551);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_5552);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5553);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5554);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5555);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5556);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5557);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5558);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5559);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5560);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5561);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5562);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5563);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5564);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5565);
							}
						}
					}
				}
			}
		}
		for (y = y243 + 4, yp_1 = y243_p_0, yp_0 = 0;y < y243 + 4 + 30;y += 6, yp_1 += 6, yp_0 += 6){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x477 = x478, x477_p_0 = 0;x477 < x478 + 136;x477 += 34, x477_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f240, fp_0 = 0;f < f240 + 128;f += 64, fp_0 += 64){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c360 = c361, c360_p_0 = 0;c360 < c361 + 64;c360 += 16, c360_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 64
						// T (w, 3) (3 / 1)
						for (w = w171, wp_0 = 0;w < w171 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x477, xp_1 = x477_p_0, xp_0 = 0;x < x477 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5566 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5567 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5568 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_5569 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_5570 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5571 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5572 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_5573 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_5574 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5575 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5576 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_5577 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_5578 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5579 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5580 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_5581 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_5582 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5583 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5584 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_5585 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_5586 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5587 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5588 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_5589 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c360, cp_1 = c360_p_0, cp_0 = 0;c < c360 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5566);
											mem_vec_5566 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5567);
											mem_vec_5567 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5568);
											mem_vec_5568 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5569);
											mem_vec_5569 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5570);
											mem_vec_5570 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5571);
											mem_vec_5571 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5572);
											mem_vec_5572 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5573);
											mem_vec_5573 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5574);
											mem_vec_5574 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5575);
											mem_vec_5575 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5576);
											mem_vec_5576 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5577);
											mem_vec_5577 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5578);
											mem_vec_5578 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5579);
											mem_vec_5579 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5580);
											mem_vec_5580 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5581);
											mem_vec_5581 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5582);
											mem_vec_5582 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5583);
											mem_vec_5583 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5584);
											mem_vec_5584 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5585);
											mem_vec_5585 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5586);
											mem_vec_5586 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5587);
											mem_vec_5587 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5588);
											mem_vec_5588 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5589);
											mem_vec_5589 = vec_33;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5566);
											mem_vec_5566 = vec_34;
											vec_38 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5567);
											mem_vec_5567 = vec_37;
											vec_40 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5568);
											mem_vec_5568 = vec_39;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5569);
											mem_vec_5569 = vec_41;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5570);
											mem_vec_5570 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5571);
											mem_vec_5571 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5572);
											mem_vec_5572 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5573);
											mem_vec_5573 = vec_47;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5574);
											mem_vec_5574 = vec_48;
											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5575);
											mem_vec_5575 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5576);
											mem_vec_5576 = vec_51;
											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5577);
											mem_vec_5577 = vec_52;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5578);
											mem_vec_5578 = vec_53;
											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5579);
											mem_vec_5579 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5580);
											mem_vec_5580 = vec_56;
											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5581);
											mem_vec_5581 = vec_57;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5582);
											mem_vec_5582 = vec_58;
											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5583);
											mem_vec_5583 = vec_60;
											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5584);
											mem_vec_5584 = vec_61;
											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5585);
											mem_vec_5585 = vec_62;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5586);
											mem_vec_5586 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5587);
											mem_vec_5587 = vec_65;
											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5588);
											mem_vec_5588 = vec_66;
											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5589);
											mem_vec_5589 = vec_67;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5566);
											mem_vec_5566 = vec_68;
											vec_72 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5567);
											mem_vec_5567 = vec_71;
											vec_74 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5568);
											mem_vec_5568 = vec_73;
											vec_76 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5569);
											mem_vec_5569 = vec_75;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5570);
											mem_vec_5570 = vec_77;
											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5571);
											mem_vec_5571 = vec_79;
											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5572);
											mem_vec_5572 = vec_80;
											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5573);
											mem_vec_5573 = vec_81;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);
											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5574);
											mem_vec_5574 = vec_82;
											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5575);
											mem_vec_5575 = vec_84;
											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5576);
											mem_vec_5576 = vec_85;
											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5577);
											mem_vec_5577 = vec_86;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);
											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5578);
											mem_vec_5578 = vec_87;
											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5579);
											mem_vec_5579 = vec_89;
											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5580);
											mem_vec_5580 = vec_90;
											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5581);
											mem_vec_5581 = vec_91;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);
											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5582);
											mem_vec_5582 = vec_92;
											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5583);
											mem_vec_5583 = vec_94;
											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5584);
											mem_vec_5584 = vec_95;
											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5585);
											mem_vec_5585 = vec_96;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);
											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5586);
											mem_vec_5586 = vec_97;
											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5587);
											mem_vec_5587 = vec_99;
											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5588);
											mem_vec_5588 = vec_100;
											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5589);
											mem_vec_5589 = vec_101;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5566);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5567);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_5568);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5569);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5570);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5571);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5572);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5573);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5574);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5575);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5576);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5577);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5578);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5579);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5580);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5581);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5582);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5583);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_5584);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_5585);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5586);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5587);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_5588);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_5589);
							}
						}
					}
				}
			}
		}
}
}
