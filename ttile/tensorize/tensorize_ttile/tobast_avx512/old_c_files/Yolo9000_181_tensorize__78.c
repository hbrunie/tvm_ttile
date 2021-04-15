
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (1, f);
  T (256, c); T (16, f)]
*/
IND_TYPE c, cp_0, c430_p_0, cp_1, c430, f, fp_0, f466_p_0, f467_p_0, fp_1, f466_p_1, fp_2, f466, f467, w, wp_0, x, xp_0, x384_p_0, xp_1, x384, y, yp_0;
IND_TYPE y256 = 0;
IND_TYPE x385 = 0;
IND_TYPE h = 0;
IND_TYPE w256 = 0;
IND_TYPE c431 = 0;
IND_TYPE f468 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3654 ,mem_vec_3655 ,mem_vec_3656 ,mem_vec_3657 ,mem_vec_3658 ,mem_vec_3659 ,mem_vec_3660 ,mem_vec_3661 ,mem_vec_3662 ,mem_vec_3663 ,mem_vec_3664 ,mem_vec_3665 ,mem_vec_3666 ,mem_vec_3667 ,mem_vec_3668 ,mem_vec_3669 ,mem_vec_3670 ,mem_vec_3671 ,mem_vec_3672 ,mem_vec_3673 ,mem_vec_3674 ,mem_vec_3675 ,mem_vec_3676 ,mem_vec_3677 ,mem_vec_3678 ,mem_vec_3679 ,mem_vec_3680 ,mem_vec_3681 ,mem_vec_3682 ,mem_vec_3683 ,mem_vec_3684 ,mem_vec_3685 ,mem_vec_3686 ,mem_vec_3687 ,mem_vec_3688 ,mem_vec_3689 ,mem_vec_3690 ,mem_vec_3691 ,mem_vec_3692 ,mem_vec_3693 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 16) (1024 / 64)
f467 = 0;
f467_p_0 = 0;
c430 = 0;
c430_p_0 = 0;
f466 = 0;
f466_p_1 = 0;
y = 0;
yp_0 = 0;
x384 = 0;
x384_p_0 = 0;
f = 0;
fp_2 = 0;
							for (w = w256, wp_0 = 0;w < w256 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 2, f = 64
								// T (x, 17) (17 / 1)
								for (x = x384, xp_1 = x384_p_0, xp_0 = 0;x < x384 + 17;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3654 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_3655 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_3656 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
											mem_vec_3657 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
											mem_vec_3658 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_3659 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_3660 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
											mem_vec_3661 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
											mem_vec_3662 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_3663 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_3664 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
											mem_vec_3665 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
											// T (c, 2) (2 / 1)
											for (c = c430, cp_1 = c430_p_0, cp_0 = 0;c < c430 + 2;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3654);
												mem_vec_3654 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3655);
												mem_vec_3655 = vec_3;
												vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3656);
												mem_vec_3656 = vec_5;
												vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3657);
												mem_vec_3657 = vec_7;
												scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);
												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3658);
												mem_vec_3658 = vec_9;
												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3659);
												mem_vec_3659 = vec_11;
												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3660);
												mem_vec_3660 = vec_12;
												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3661);
												mem_vec_3661 = vec_13;
												scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3662);
												mem_vec_3662 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3663);
												mem_vec_3663 = vec_16;
												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3664);
												mem_vec_3664 = vec_17;
												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3665);
												mem_vec_3665 = vec_18;
												scal_3 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_3654);
												mem_vec_3654 = vec_19;
												vec_23 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_3655);
												mem_vec_3655 = vec_22;
												vec_25 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_3656);
												mem_vec_3656 = vec_24;
												vec_27 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_3657);
												mem_vec_3657 = vec_26;
												scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_3658);
												mem_vec_3658 = vec_28;
												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_3659);
												mem_vec_3659 = vec_30;
												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_3660);
												mem_vec_3660 = vec_31;
												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_3661);
												mem_vec_3661 = vec_32;
												scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
												vec_34 = _mm512_set1_ps(scal_5);
												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_3662);
												mem_vec_3662 = vec_33;
												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_3663);
												mem_vec_3663 = vec_35;
												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_3664);
												mem_vec_3664 = vec_36;
												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_3665);
												mem_vec_3665 = vec_37;
												scal_6 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_3654);
												mem_vec_3654 = vec_38;
												vec_42 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_3655);
												mem_vec_3655 = vec_41;
												vec_44 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_3656);
												mem_vec_3656 = vec_43;
												vec_46 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_3657);
												mem_vec_3657 = vec_45;
												scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_7);
												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_3658);
												mem_vec_3658 = vec_47;
												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_3659);
												mem_vec_3659 = vec_49;
												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_3660);
												mem_vec_3660 = vec_50;
												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_3661);
												mem_vec_3661 = vec_51;
												scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
												vec_53 = _mm512_set1_ps(scal_8);
												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_3662);
												mem_vec_3662 = vec_52;
												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_3663);
												mem_vec_3663 = vec_54;
												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_3664);
												mem_vec_3664 = vec_55;
												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_3665);
												mem_vec_3665 = vec_56;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_3654);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_3655);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_3656);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_3657);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_3658);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_3659);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_3660);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_3661);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_3662);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_3663);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_3664);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_3665);
								}
							}
}
