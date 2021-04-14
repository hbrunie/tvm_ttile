
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))];
  T (1, f); T (4, c); T (4, f); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c966_p_0, cp_1, c966, f, fp_0, f1288_p_0, f1289_p_0, fp_1, f1288_p_1, fp_2, f1288, f1289, h, hp_0, w, wp_0, x, xp_0, x1018_p_0, xp_1, x1018, y, yp_0;
IND_TYPE y644 = 0;
IND_TYPE x1019 = 0;
IND_TYPE h644 = 0;
IND_TYPE w592 = 0;
IND_TYPE c967 = 0;
IND_TYPE f1290 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12680 ,mem_vec_12681 ,mem_vec_12682 ,mem_vec_12683 ,mem_vec_12684 ,mem_vec_12685 ,mem_vec_12686 ,mem_vec_12687 ,mem_vec_12688 ,mem_vec_12689 ,mem_vec_12690 ,mem_vec_12691 ,mem_vec_12692 ,mem_vec_12693 ,mem_vec_12694 ,mem_vec_12695 ,mem_vec_12696 ,mem_vec_12697 ,mem_vec_12698 ,mem_vec_12699 ,mem_vec_12700 ,mem_vec_12701 ,mem_vec_12702 ,mem_vec_12703 ,mem_vec_12704 ,mem_vec_12705 ,mem_vec_12706 ,mem_vec_12707 ,mem_vec_12708 ,mem_vec_12709 ,mem_vec_12710 ,mem_vec_12711 ,mem_vec_12712 ,mem_vec_12713 ,mem_vec_12714 ,mem_vec_12715 ,mem_vec_12716 ,mem_vec_12717 ,mem_vec_12718 ,mem_vec_12719 ,mem_vec_12720 ,mem_vec_12721 ,mem_vec_12722 ,mem_vec_12723 ,mem_vec_12724 ,mem_vec_12725 ,mem_vec_12726 ,mem_vec_12727 ,mem_vec_12728 ,mem_vec_12729 ,mem_vec_12730 ,mem_vec_12731 ,mem_vec_12732 ,mem_vec_12733 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f1289 = 0;
f1289_p_0 = 0;
x1018 = 0;
x1018_p_0 = 0;
f1288 = 0;
f1288_p_1 = 0;
c966 = 0;
c966_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h644, hp_0 = 0;h < h644 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w592, wp_0 = 0;w < w592 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 1, c = 32, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1018, xp_1 = x1018_p_0, xp_0 = 0;x < x1018 + 4;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12680 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_12681 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_12682 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_12683 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_12684 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_12685 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_12686 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_12687 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_12688 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_12689 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_12690 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_12691 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_12692 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_12693 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_12694 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_12695 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_12696 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_12697 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_12698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_12699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_12700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_12701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_12702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_12703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_12704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_12705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c966, cp_1 = c966_p_0, cp_0 = 0;c < c966 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12680);
													mem_vec_12680 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12681);
													mem_vec_12681 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12682);
													mem_vec_12682 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12683);
													mem_vec_12683 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12684);
													mem_vec_12684 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12685);
													mem_vec_12685 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12686);
													mem_vec_12686 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12687);
													mem_vec_12687 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12688);
													mem_vec_12688 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12689);
													mem_vec_12689 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12690);
													mem_vec_12690 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12691);
													mem_vec_12691 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12692);
													mem_vec_12692 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12693);
													mem_vec_12693 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12694);
													mem_vec_12694 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12695);
													mem_vec_12695 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12696);
													mem_vec_12696 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12697);
													mem_vec_12697 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12698);
													mem_vec_12698 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12699);
													mem_vec_12699 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12700);
													mem_vec_12700 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12701);
													mem_vec_12701 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12702);
													mem_vec_12702 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12703);
													mem_vec_12703 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12704);
													mem_vec_12704 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12705);
													mem_vec_12705 = vec_40;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12680);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12681);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12682);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12683);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12684);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12685);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12686);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12687);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_12688);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_12689);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_12690);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_12691);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_12692);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_12693);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_12694);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_12695);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_12696);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_12697);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_12698);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_12699);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_12700);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_12701);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_12702);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_12703);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_12704);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_12705);
									}
								}
							}
}
