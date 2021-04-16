
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (16, f);
  T (1, x); T (2, y)]
*/
IND_TYPE c, cp_0, c544_p_0, cp_1, c544, f, fp_0, h, hp_0, x, xp_0, x543_p_0, xp_1, x543, y, yp_0, y411_p_0, yp_1, y411;
IND_TYPE y412 = 0;
IND_TYPE x544 = 0;
IND_TYPE h326 = 0;
IND_TYPE w = 0;
IND_TYPE c545 = 0;
IND_TYPE f602 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6698 ,mem_vec_6699 ,mem_vec_6700 ,mem_vec_6701 ,mem_vec_6702 ,mem_vec_6703 ,mem_vec_6704 ,mem_vec_6705 ,mem_vec_6706 ,mem_vec_6707 ,mem_vec_6708 ,mem_vec_6709 ,mem_vec_6710 ,mem_vec_6711 ,mem_vec_6712 ,mem_vec_6713 ,mem_vec_6714 ,mem_vec_6715 ,mem_vec_6716 ,mem_vec_6717 ,mem_vec_6718 ,mem_vec_6719 ,mem_vec_6720 ,mem_vec_6721 ,mem_vec_6722 ,mem_vec_6723 ,mem_vec_6724 ,mem_vec_6725 ,mem_vec_6726 ,mem_vec_6727 ,mem_vec_6728 ,mem_vec_6729 ,mem_vec_6730 ,mem_vec_6731 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (y, 2) (34 / 17)
y411 = 0;
y411_p_0 = 0;
x543 = 0;
x543_p_0 = 0;
		for (f = f602, fp_0 = 0;f < f602 + 512;f += 32, fp_0 += 32){
				for (y = y411, yp_1 = y411_p_0, yp_0 = 0;y < y411 + 8;y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c544 = c545, c544_p_0 = 0;c544 < c545 + 256;c544 += 32, c544_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h326, hp_0 = 0;h < h326 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x543, xp_1 = x543_p_0, xp_0 = 0;x < x543 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6708 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_6709 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_6710 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_6711 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_6712 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_6713 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c544, cp_1 = c544_p_0, cp_0 = 0;c < c544 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6698);
											mem_vec_6698 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6699);
											mem_vec_6699 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6700);
											mem_vec_6700 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6701);
											mem_vec_6701 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6702);
											mem_vec_6702 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6703);
											mem_vec_6703 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6704);
											mem_vec_6704 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6705);
											mem_vec_6705 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6706);
											mem_vec_6706 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6707);
											mem_vec_6707 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6708);
											mem_vec_6708 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6709);
											mem_vec_6709 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6710);
											mem_vec_6710 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6711);
											mem_vec_6711 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6712);
											mem_vec_6712 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6713);
											mem_vec_6713 = vec_25;
											scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_6698);
											mem_vec_6698 = vec_26;
											vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_6699);
											mem_vec_6699 = vec_29;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_6700);
											mem_vec_6700 = vec_31;
											vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_6701);
											mem_vec_6701 = vec_33;
											scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_6702);
											mem_vec_6702 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_6703);
											mem_vec_6703 = vec_36;
											scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_6704);
											mem_vec_6704 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_6705);
											mem_vec_6705 = vec_39;
											scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_6706);
											mem_vec_6706 = vec_40;
											vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_6707);
											mem_vec_6707 = vec_42;
											scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_6708);
											mem_vec_6708 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_6709);
											mem_vec_6709 = vec_45;
											scal_14 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_6710);
											mem_vec_6710 = vec_46;
											vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_6711);
											mem_vec_6711 = vec_48;
											scal_15 = input[strideA1 * (x + w + 1) + strideA2 * (y + 7 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_6712);
											mem_vec_6712 = vec_49;
											vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_6713);
											mem_vec_6713 = vec_51;
											scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_6698);
											mem_vec_6698 = vec_52;
											vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_6699);
											mem_vec_6699 = vec_55;
											scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_6700);
											mem_vec_6700 = vec_57;
											vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_6701);
											mem_vec_6701 = vec_59;
											scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_61 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_6702);
											mem_vec_6702 = vec_60;
											vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_6703);
											mem_vec_6703 = vec_62;
											scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_6704);
											mem_vec_6704 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_6705);
											mem_vec_6705 = vec_65;
											scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_6706);
											mem_vec_6706 = vec_66;
											vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_6707);
											mem_vec_6707 = vec_68;
											scal_21 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_6708);
											mem_vec_6708 = vec_69;
											vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_6709);
											mem_vec_6709 = vec_71;
											scal_22 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_6710);
											mem_vec_6710 = vec_72;
											vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_6711);
											mem_vec_6711 = vec_74;
											scal_23 = input[strideA1 * (x + w + 2) + strideA2 * (y + 7 + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_6712);
											mem_vec_6712 = vec_75;
											vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_6713);
											mem_vec_6713 = vec_77;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6698);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6699);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6700);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6701);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6702);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6703);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6704);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6705);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6706);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6707);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6708);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6709);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6710);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6711);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6712);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6713);
							}
						}
					}
				}
				for (y = y411 + 8, yp_1 = y411_p_0, yp_0 = 0;y < y411 + 8 + 9;y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c544 = c545, c544_p_0 = 0;c544 < c545 + 256;c544 += 32, c544_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h326, hp_0 = 0;h < h326 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x543, xp_1 = x543_p_0, xp_0 = 0;x < x543 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6714 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6715 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6716 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6717 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6718 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6719 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6720 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6721 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6722 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6723 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6724 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_6725 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_6726 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_6727 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_6728 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_6729 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_6730 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_6731 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c544, cp_1 = c544_p_0, cp_0 = 0;c < c544 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6714);
											mem_vec_6714 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6715);
											mem_vec_6715 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6716);
											mem_vec_6716 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6717);
											mem_vec_6717 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6718);
											mem_vec_6718 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6719);
											mem_vec_6719 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6720);
											mem_vec_6720 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6721);
											mem_vec_6721 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6722);
											mem_vec_6722 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6723);
											mem_vec_6723 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6724);
											mem_vec_6724 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6725);
											mem_vec_6725 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6726);
											mem_vec_6726 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6727);
											mem_vec_6727 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6728);
											mem_vec_6728 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6729);
											mem_vec_6729 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6730);
											mem_vec_6730 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6731);
											mem_vec_6731 = vec_28;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6714);
											mem_vec_6714 = vec_29;
											vec_33 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6715);
											mem_vec_6715 = vec_32;
											scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_6716);
											mem_vec_6716 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_6717);
											mem_vec_6717 = vec_36;
											scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_6718);
											mem_vec_6718 = vec_37;
											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_6719);
											mem_vec_6719 = vec_39;
											scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_6720);
											mem_vec_6720 = vec_40;
											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_6721);
											mem_vec_6721 = vec_42;
											scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6722);
											mem_vec_6722 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6723);
											mem_vec_6723 = vec_45;
											scal_14 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_6724);
											mem_vec_6724 = vec_46;
											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_6725);
											mem_vec_6725 = vec_48;
											scal_15 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);
											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_6726);
											mem_vec_6726 = vec_49;
											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_6727);
											mem_vec_6727 = vec_51;
											scal_16 = input[strideA1 * (x + w + 1) + strideA2 * (y + 7 + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);
											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_6728);
											mem_vec_6728 = vec_52;
											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_6729);
											mem_vec_6729 = vec_54;
											scal_17 = input[strideA1 * (x + w + 1) + strideA2 * (y + 8 + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);
											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_6730);
											mem_vec_6730 = vec_55;
											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_6731);
											mem_vec_6731 = vec_57;
											scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6714);
											mem_vec_6714 = vec_58;
											vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6715);
											mem_vec_6715 = vec_61;
											scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_6716);
											mem_vec_6716 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_6717);
											mem_vec_6717 = vec_65;
											scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_6718);
											mem_vec_6718 = vec_66;
											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_6719);
											mem_vec_6719 = vec_68;
											scal_21 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);
											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_6720);
											mem_vec_6720 = vec_69;
											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_6721);
											mem_vec_6721 = vec_71;
											scal_22 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6722);
											mem_vec_6722 = vec_72;
											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6723);
											mem_vec_6723 = vec_74;
											scal_23 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);
											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_6724);
											mem_vec_6724 = vec_75;
											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_6725);
											mem_vec_6725 = vec_77;
											scal_24 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_6726);
											mem_vec_6726 = vec_78;
											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_6727);
											mem_vec_6727 = vec_80;
											scal_25 = input[strideA1 * (x + w + 2) + strideA2 * (y + 7 + h) + c];
											vec_82 = _mm512_set1_ps(scal_25);
											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_6728);
											mem_vec_6728 = vec_81;
											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_6729);
											mem_vec_6729 = vec_83;
											scal_26 = input[strideA1 * (x + w + 2) + strideA2 * (y + 8 + h) + c];
											vec_85 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_6730);
											mem_vec_6730 = vec_84;
											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_6731);
											mem_vec_6731 = vec_86;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6714);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6715);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6716);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6717);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6718);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6719);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6720);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6721);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6722);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6723);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_6724);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_6725);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_6726);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_6727);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_6728);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_6729);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_6730);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_6731);
							}
						}
					}
				}
		}
}
