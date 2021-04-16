
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (4, c); T (2, f); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (4, y)]
*/
IND_TYPE c, cp_0, c378_p_0, cp_1, c378, f, fp_0, h, hp_0, x, xp_0, x495_p_0, xp_1, x495, y, yp_0, y261_p_0, yp_1, y261;
IND_TYPE y262 = 0;
IND_TYPE x496 = 0;
IND_TYPE h167 = 0;
IND_TYPE w = 0;
IND_TYPE c379 = 0;
IND_TYPE f252 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5802 ,mem_vec_5803 ,mem_vec_5804 ,mem_vec_5805 ,mem_vec_5806 ,mem_vec_5807 ,mem_vec_5808 ,mem_vec_5809 ,mem_vec_5810 ,mem_vec_5811 ,mem_vec_5812 ,mem_vec_5813 ,mem_vec_5814 ,mem_vec_5815 ,mem_vec_5816 ,mem_vec_5817 ,mem_vec_5818 ,mem_vec_5819 ,mem_vec_5820 ,mem_vec_5821 ,mem_vec_5822 ,mem_vec_5823 ,mem_vec_5824 ,mem_vec_5825 ,mem_vec_5826 ,mem_vec_5827 ,mem_vec_5828 ,mem_vec_5829 ,mem_vec_5830 ,mem_vec_5831 ,mem_vec_5832 ,mem_vec_5833 ,mem_vec_5834 ,mem_vec_5835 ,mem_vec_5836 ,mem_vec_5837 ,mem_vec_5838 ,mem_vec_5839 ,mem_vec_5840 ,mem_vec_5841 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (y, 4) (136 / 34)
for (y261 = y262, y261_p_0 = 0;y261 < y262 + 136;y261 += 34, y261_p_0 += 34){
		for (y = y261, yp_1 = y261_p_0, yp_0 = 0;y < y261 + 4;y += 4, yp_1 += 4, yp_0 += 4){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x495 = x496, x495_p_0 = 0;x495 < x496 + 136;x495 += 34, x495_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f252, fp_0 = 0;f < f252 + 128;f += 64, fp_0 += 64){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c378 = c379, c378_p_0 = 0;c378 < c379 + 64;c378 += 16, c378_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h167, hp_0 = 0;h < h167 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x495, xp_1 = x495_p_0, xp_0 = 0;x < x495 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5804 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_5805 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_5806 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5807 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5808 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_5809 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_5810 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5811 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5812 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_5813 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_5814 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5815 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5816 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_5817 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c378, cp_1 = c378_p_0, cp_0 = 0;c < c378 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5802);
											mem_vec_5802 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5803);
											mem_vec_5803 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5804);
											mem_vec_5804 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5805);
											mem_vec_5805 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5806);
											mem_vec_5806 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5807);
											mem_vec_5807 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5808);
											mem_vec_5808 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5809);
											mem_vec_5809 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5810);
											mem_vec_5810 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5811);
											mem_vec_5811 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5812);
											mem_vec_5812 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5813);
											mem_vec_5813 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5814);
											mem_vec_5814 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5815);
											mem_vec_5815 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5816);
											mem_vec_5816 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5817);
											mem_vec_5817 = vec_23;
											scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_5802);
											mem_vec_5802 = vec_24;
											vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_5803);
											mem_vec_5803 = vec_27;
											vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_5804);
											mem_vec_5804 = vec_29;
											vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_5805);
											mem_vec_5805 = vec_31;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);
											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_5806);
											mem_vec_5806 = vec_33;
											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_5807);
											mem_vec_5807 = vec_35;
											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5808);
											mem_vec_5808 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5809);
											mem_vec_5809 = vec_37;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_5810);
											mem_vec_5810 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_5811);
											mem_vec_5811 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_5812);
											mem_vec_5812 = vec_41;
											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_5813);
											mem_vec_5813 = vec_42;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_5814);
											mem_vec_5814 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5815);
											mem_vec_5815 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5816);
											mem_vec_5816 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_5817);
											mem_vec_5817 = vec_47;
											scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_5802);
											mem_vec_5802 = vec_48;
											vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_5803);
											mem_vec_5803 = vec_51;
											vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_5804);
											mem_vec_5804 = vec_53;
											vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_5805);
											mem_vec_5805 = vec_55;
											scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5806);
											mem_vec_5806 = vec_57;
											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_5807);
											mem_vec_5807 = vec_59;
											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5808);
											mem_vec_5808 = vec_60;
											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5809);
											mem_vec_5809 = vec_61;
											scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);
											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_5810);
											mem_vec_5810 = vec_62;
											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_5811);
											mem_vec_5811 = vec_64;
											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_5812);
											mem_vec_5812 = vec_65;
											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_5813);
											mem_vec_5813 = vec_66;
											scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_5814);
											mem_vec_5814 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_5815);
											mem_vec_5815 = vec_69;
											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_5816);
											mem_vec_5816 = vec_70;
											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_5817);
											mem_vec_5817 = vec_71;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5802);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5803);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_5804);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5805);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5806);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5807);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5808);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5809);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5810);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5811);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5812);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5813);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5814);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5815);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5816);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5817);
							}
						}
					}
				}
			}
		}
		for (y = y261 + 4, yp_1 = y261_p_0, yp_0 = 0;y < y261 + 4 + 30;y += 6, yp_1 += 6, yp_0 += 6){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x495 = x496, x495_p_0 = 0;x495 < x496 + 136;x495 += 34, x495_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 2) (128 / 64)
				for (f = f252, fp_0 = 0;f < f252 + 128;f += 64, fp_0 += 64){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (c, 4) (64 / 16)
					for (c378 = c379, c378_p_0 = 0;c378 < c379 + 64;c378 += 16, c378_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h167, hp_0 = 0;h < h167 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 16, f = 64
							// T (x, 34) (34 / 1)
							for (x = x495, xp_1 = x495_p_0, xp_0 = 0;x < x495 + 34;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5818 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5819 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5820 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_5821 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_5822 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5823 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5824 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_5825 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_5826 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5827 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5828 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_5829 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_5830 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5831 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5832 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_5833 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_5834 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5835 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5836 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_5837 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_5838 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5839 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5840 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_5841 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c378, cp_1 = c378_p_0, cp_0 = 0;c < c378 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5818);
											mem_vec_5818 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5819);
											mem_vec_5819 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5820);
											mem_vec_5820 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5821);
											mem_vec_5821 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5822);
											mem_vec_5822 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5823);
											mem_vec_5823 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5824);
											mem_vec_5824 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5825);
											mem_vec_5825 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5826);
											mem_vec_5826 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5827);
											mem_vec_5827 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5828);
											mem_vec_5828 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5829);
											mem_vec_5829 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5830);
											mem_vec_5830 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5831);
											mem_vec_5831 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5832);
											mem_vec_5832 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5833);
											mem_vec_5833 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5834);
											mem_vec_5834 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5835);
											mem_vec_5835 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5836);
											mem_vec_5836 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5837);
											mem_vec_5837 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5838);
											mem_vec_5838 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5839);
											mem_vec_5839 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5840);
											mem_vec_5840 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5841);
											mem_vec_5841 = vec_33;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5818);
											mem_vec_5818 = vec_34;
											vec_38 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5819);
											mem_vec_5819 = vec_37;
											vec_40 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5820);
											mem_vec_5820 = vec_39;
											vec_42 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5821);
											mem_vec_5821 = vec_41;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5822);
											mem_vec_5822 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5823);
											mem_vec_5823 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5824);
											mem_vec_5824 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5825);
											mem_vec_5825 = vec_47;
											scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5826);
											mem_vec_5826 = vec_48;
											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5827);
											mem_vec_5827 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5828);
											mem_vec_5828 = vec_51;
											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5829);
											mem_vec_5829 = vec_52;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5830);
											mem_vec_5830 = vec_53;
											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5831);
											mem_vec_5831 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5832);
											mem_vec_5832 = vec_56;
											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5833);
											mem_vec_5833 = vec_57;
											scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5834);
											mem_vec_5834 = vec_58;
											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5835);
											mem_vec_5835 = vec_60;
											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5836);
											mem_vec_5836 = vec_61;
											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5837);
											mem_vec_5837 = vec_62;
											scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);
											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5838);
											mem_vec_5838 = vec_63;
											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5839);
											mem_vec_5839 = vec_65;
											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5840);
											mem_vec_5840 = vec_66;
											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5841);
											mem_vec_5841 = vec_67;
											scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5818);
											mem_vec_5818 = vec_68;
											vec_72 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5819);
											mem_vec_5819 = vec_71;
											vec_74 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5820);
											mem_vec_5820 = vec_73;
											vec_76 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5821);
											mem_vec_5821 = vec_75;
											scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5822);
											mem_vec_5822 = vec_77;
											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5823);
											mem_vec_5823 = vec_79;
											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5824);
											mem_vec_5824 = vec_80;
											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5825);
											mem_vec_5825 = vec_81;
											scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);
											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5826);
											mem_vec_5826 = vec_82;
											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5827);
											mem_vec_5827 = vec_84;
											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5828);
											mem_vec_5828 = vec_85;
											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5829);
											mem_vec_5829 = vec_86;
											scal_15 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);
											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5830);
											mem_vec_5830 = vec_87;
											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5831);
											mem_vec_5831 = vec_89;
											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5832);
											mem_vec_5832 = vec_90;
											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5833);
											mem_vec_5833 = vec_91;
											scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);
											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5834);
											mem_vec_5834 = vec_92;
											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5835);
											mem_vec_5835 = vec_94;
											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5836);
											mem_vec_5836 = vec_95;
											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5837);
											mem_vec_5837 = vec_96;
											scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);
											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5838);
											mem_vec_5838 = vec_97;
											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5839);
											mem_vec_5839 = vec_99;
											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5840);
											mem_vec_5840 = vec_100;
											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5841);
											mem_vec_5841 = vec_101;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5818);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5819);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_5820);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_5821);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5822);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5823);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_5824);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_5825);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5826);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5827);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_5828);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_5829);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5830);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5831);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_5832);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_5833);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5834);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5835);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_5836);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_5837);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5838);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5839);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_5840);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_5841);
							}
						}
					}
				}
			}
		}
}
}
