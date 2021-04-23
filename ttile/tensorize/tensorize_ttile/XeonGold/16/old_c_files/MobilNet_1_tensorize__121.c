
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (14, x);
  T (2, c); T (3, w); T (8, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 2), (Arg 14))]; T (2, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c579_p_0, cp_1, c579, f, fp_0, w, wp_0, x, xp_0, x523_p_0, xp_1, x523, y, yp_0, y579_p_0, yp_1, y579;
IND_TYPE y580 = 0;
IND_TYPE x524 = 0;
IND_TYPE h = 0;
IND_TYPE w386 = 0;
IND_TYPE c580 = 0;
IND_TYPE f330 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4654 ,mem_vec_4655 ,mem_vec_4656 ,mem_vec_4657 ,mem_vec_4658 ,mem_vec_4659 ,mem_vec_4660 ,mem_vec_4661 ,mem_vec_4662 ,mem_vec_4663 ,mem_vec_4664 ,mem_vec_4665 ,mem_vec_4666 ,mem_vec_4667 ,mem_vec_4668 ,mem_vec_4669 ,mem_vec_4670 ,mem_vec_4671 ,mem_vec_4672 ,mem_vec_4673 ,mem_vec_4674 ,mem_vec_4675 ,mem_vec_4676 ,mem_vec_4677 ,mem_vec_4678 ,mem_vec_4679 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 1) (112 / 112)
y579 = 0;
y579_p_0 = 0;
	for (f = f330, fp_0 = 0;f < f330 + 32;f += 16, fp_0 += 16){
			for (y = y579, yp_1 = y579_p_0, yp_0 = 0;y < y579 + 84;y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 16
				// T (x, 8) (112 / 14)
				for (x523 = x524, x523_p_0 = 0;x523 < x524 + 112;x523 += 14, x523_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w386, wp_0 = 0;w < w386 + 3;w += 1, wp_0 += 1){
						// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c579 = c580, c579_p_0 = 0;c579 < c580 + 32;c579 += 16, c579_p_0 += 16){
							// y = ph_y, x = 14, h = 3, w = 1, c = 16, f = 16
							// T (x, 14) (14 / 1)
							for (x = x523, xp_1 = x523_p_0, xp_0 = 0;x < x523 + 14;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4654 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4655 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4656 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4657 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4658 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4659 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4660 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4661 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4662 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4663 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4664 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4665 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c579, cp_1 = c579_p_0, cp_0 = 0;c < c579 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4654);
											mem_vec_4654 = vec_0;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4655);
											mem_vec_4655 = vec_3;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4656);
											mem_vec_4656 = vec_5;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4657);
											mem_vec_4657 = vec_7;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4658);
											mem_vec_4658 = vec_9;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4659);
											mem_vec_4659 = vec_11;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_4660);
											mem_vec_4660 = vec_13;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_4661);
											mem_vec_4661 = vec_15;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4662);
											mem_vec_4662 = vec_17;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4663);
											mem_vec_4663 = vec_19;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);
											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_4664);
											mem_vec_4664 = vec_21;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4665);
											mem_vec_4665 = vec_23;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_26 = _mm512_set1_ps(scal_12);
											vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_4654);
											mem_vec_4654 = vec_25;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);
											vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4655);
											mem_vec_4655 = vec_28;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_4656);
											mem_vec_4656 = vec_30;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_4657);
											mem_vec_4657 = vec_32;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_4658);
											mem_vec_4658 = vec_34;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);
											vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_4659);
											mem_vec_4659 = vec_36;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_4660);
											mem_vec_4660 = vec_38;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_4661);
											mem_vec_4661 = vec_40;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);
											vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_4662);
											mem_vec_4662 = vec_42;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);
											vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_4663);
											mem_vec_4663 = vec_44;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_4664);
											mem_vec_4664 = vec_46;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_4665);
											mem_vec_4665 = vec_48;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_51 = _mm512_set1_ps(scal_24);
											vec_52 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_4654);
											mem_vec_4654 = vec_50;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_4655);
											mem_vec_4655 = vec_53;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_4656);
											mem_vec_4656 = vec_55;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_4657);
											mem_vec_4657 = vec_57;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);
											vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_4658);
											mem_vec_4658 = vec_59;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_4659);
											mem_vec_4659 = vec_61;
											scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_4660);
											mem_vec_4660 = vec_63;
											scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);
											vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_4661);
											mem_vec_4661 = vec_65;
											scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_4662);
											mem_vec_4662 = vec_67;
											scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_4663);
											mem_vec_4663 = vec_69;
											scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);
											vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_4664);
											mem_vec_4664 = vec_71;
											scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);
											vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_4665);
											mem_vec_4665 = vec_73;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4654);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4655);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4656);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4657);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4658);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4659);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4660);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4661);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4662);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4663);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4664);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4665);
							}
						}
					}
				}
			}
			for (y = y579 + 84, yp_1 = y579_p_0, yp_0 = 0;y < y579 + 84 + 28;y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 16
				// T (x, 8) (112 / 14)
				for (x523 = x524, x523_p_0 = 0;x523 < x524 + 112;x523 += 14, x523_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w386, wp_0 = 0;w < w386 + 3;w += 1, wp_0 += 1){
						// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c579 = c580, c579_p_0 = 0;c579 < c580 + 32;c579 += 16, c579_p_0 += 16){
							// y = ph_y, x = 14, h = 3, w = 1, c = 16, f = 16
							// T (x, 14) (14 / 1)
							for (x = x523, xp_1 = x523_p_0, xp_0 = 0;x < x523 + 14;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4666 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4667 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4668 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4669 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4670 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4671 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4672 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4673 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4674 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4675 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_4676 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_4677 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_4678 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										mem_vec_4679 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c579, cp_1 = c579_p_0, cp_0 = 0;c < c579 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4666);
											mem_vec_4666 = vec_0;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);
											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_4667);
											mem_vec_4667 = vec_3;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4668);
											mem_vec_4668 = vec_5;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);
											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_4669);
											mem_vec_4669 = vec_7;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4670);
											mem_vec_4670 = vec_9;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4671);
											mem_vec_4671 = vec_11;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_4672);
											mem_vec_4672 = vec_13;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_4673);
											mem_vec_4673 = vec_15;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4674);
											mem_vec_4674 = vec_17;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4675);
											mem_vec_4675 = vec_19;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);
											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_4676);
											mem_vec_4676 = vec_21;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4677);
											mem_vec_4677 = vec_23;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
											vec_26 = _mm512_set1_ps(scal_12);
											vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_4678);
											mem_vec_4678 = vec_25;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
											vec_28 = _mm512_set1_ps(scal_13);
											vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_4679);
											mem_vec_4679 = vec_27;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_14);
											vec_31 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_4666);
											mem_vec_4666 = vec_29;
											scal_15 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_31, mem_vec_4667);
											mem_vec_4667 = vec_32;
											scal_16 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_4668);
											mem_vec_4668 = vec_34;
											scal_17 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);
											vec_36 = _mm512_fmadd_ps(vec_37, vec_31, mem_vec_4669);
											mem_vec_4669 = vec_36;
											scal_18 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_4670);
											mem_vec_4670 = vec_38;
											scal_19 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_4671);
											mem_vec_4671 = vec_40;
											scal_20 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);
											vec_42 = _mm512_fmadd_ps(vec_43, vec_31, mem_vec_4672);
											mem_vec_4672 = vec_42;
											scal_21 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);
											vec_44 = _mm512_fmadd_ps(vec_45, vec_31, mem_vec_4673);
											mem_vec_4673 = vec_44;
											scal_22 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_4674);
											mem_vec_4674 = vec_46;
											scal_23 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_4675);
											mem_vec_4675 = vec_48;
											scal_24 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 1) + c];
											vec_51 = _mm512_set1_ps(scal_24);
											vec_50 = _mm512_fmadd_ps(vec_51, vec_31, mem_vec_4676);
											mem_vec_4676 = vec_50;
											scal_25 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_25);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_4677);
											mem_vec_4677 = vec_52;
											scal_26 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h + 1) + c];
											vec_55 = _mm512_set1_ps(scal_26);
											vec_54 = _mm512_fmadd_ps(vec_55, vec_31, mem_vec_4678);
											mem_vec_4678 = vec_54;
											scal_27 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h + 1) + c];
											vec_57 = _mm512_set1_ps(scal_27);
											vec_56 = _mm512_fmadd_ps(vec_57, vec_31, mem_vec_4679);
											mem_vec_4679 = vec_56;
											scal_28 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_28);
											vec_60 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_4666);
											mem_vec_4666 = vec_58;
											scal_29 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);
											vec_61 = _mm512_fmadd_ps(vec_62, vec_60, mem_vec_4667);
											mem_vec_4667 = vec_61;
											scal_30 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_4668);
											mem_vec_4668 = vec_63;
											scal_31 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);
											vec_65 = _mm512_fmadd_ps(vec_66, vec_60, mem_vec_4669);
											mem_vec_4669 = vec_65;
											scal_32 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_4670);
											mem_vec_4670 = vec_67;
											scal_33 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_4671);
											mem_vec_4671 = vec_69;
											scal_34 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);
											vec_71 = _mm512_fmadd_ps(vec_72, vec_60, mem_vec_4672);
											mem_vec_4672 = vec_71;
											scal_35 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);
											vec_73 = _mm512_fmadd_ps(vec_74, vec_60, mem_vec_4673);
											mem_vec_4673 = vec_73;
											scal_36 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_36);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_4674);
											mem_vec_4674 = vec_75;
											scal_37 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_37);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_4675);
											mem_vec_4675 = vec_77;
											scal_38 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h + 2) + c];
											vec_80 = _mm512_set1_ps(scal_38);
											vec_79 = _mm512_fmadd_ps(vec_80, vec_60, mem_vec_4676);
											mem_vec_4676 = vec_79;
											scal_39 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_39);
											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_4677);
											mem_vec_4677 = vec_81;
											scal_40 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h + 2) + c];
											vec_84 = _mm512_set1_ps(scal_40);
											vec_83 = _mm512_fmadd_ps(vec_84, vec_60, mem_vec_4678);
											mem_vec_4678 = vec_83;
											scal_41 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h + 2) + c];
											vec_86 = _mm512_set1_ps(scal_41);
											vec_85 = _mm512_fmadd_ps(vec_86, vec_60, mem_vec_4679);
											mem_vec_4679 = vec_85;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4666);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4667);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4668);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4669);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4670);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4671);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4672);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4673);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4674);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4675);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4676);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4677);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4678);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_4679);
							}
						}
					}
				}
			}
	}
}
