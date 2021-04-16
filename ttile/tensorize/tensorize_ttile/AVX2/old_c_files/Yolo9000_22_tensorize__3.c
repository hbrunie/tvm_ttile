void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (16, y); T (1, c); T (2, f); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, x)]
*/
IND_TYPE c, cp_0, c366_p_0, cp_1, c366, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x488_p_0, x489_p_0, xp_1, x488_p_1, xp_2, x488, x489, y, yp_0, y454_p_0, yp_1, y454;
IND_TYPE y455 = 0;
IND_TYPE x490 = 0;
IND_TYPE h146 = 0;
IND_TYPE w229 = 0;
IND_TYPE c367 = 0;
IND_TYPE f239 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4704 ,mem_vec_4705 ,mem_vec_4706 ,mem_vec_4707 ,mem_vec_4708 ,mem_vec_4709 ,mem_vec_4710 ,mem_vec_4711 ,mem_vec_4712 ,mem_vec_4713 ,mem_vec_4714 ,mem_vec_4715 ,mem_vec_4716 ,mem_vec_4717 ,mem_vec_4718 ,mem_vec_4719 ,mem_vec_4720 ,mem_vec_4721 ,mem_vec_4722 ,mem_vec_4723 ,mem_vec_4724 ,mem_vec_4725 ,mem_vec_4726 ,mem_vec_4727 ,mem_vec_4728 ,mem_vec_4729 ,mem_vec_4730 ,mem_vec_4731 ,mem_vec_4732 ,mem_vec_4733 ,mem_vec_4734 ,mem_vec_4735 ,mem_vec_4736 ,mem_vec_4737 ,mem_vec_4738 ,mem_vec_4739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
x489 = 0;
x489_p_0 = 0;
y454 = 0;
y454_p_0 = 0;
x488 = 0;
x488_p_1 = 0;
f = 0;
fp_0 = 0;
c366 = 0;
c366_p_0 = 0;
y = 0;
yp_1 = 0;
x = 0;
xp_2 = 0;
								for (h = h146, hp_0 = 0;h < h146 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
									// T (w, 3) (3 / 1)
									for (w = w229, wp_0 = 0;w < w229 + 3;w += 1, wp_0 += 1){
												mem_vec_4720 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4721 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_4722 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4723 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_4724 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_4725 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_4726 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_4727 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_4728 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_4729 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_4730 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_4731 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_4732 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_4733 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_4734 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_4735 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_4736 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_4737 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_4738 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_4739 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c366, cp_1 = c366_p_0, cp_0 = 0;c < c366 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4720);
													mem_vec_4720 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4721);
													mem_vec_4721 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4722);
													mem_vec_4722 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4723);
													mem_vec_4723 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4724);
													mem_vec_4724 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4725);
													mem_vec_4725 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4726);
													mem_vec_4726 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4727);
													mem_vec_4727 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4728);
													mem_vec_4728 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4729);
													mem_vec_4729 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4730);
													mem_vec_4730 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4731);
													mem_vec_4731 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4732);
													mem_vec_4732 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4733);
													mem_vec_4733 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4734);
													mem_vec_4734 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4735);
													mem_vec_4735 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4736);
													mem_vec_4736 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4737);
													mem_vec_4737 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4738);
													mem_vec_4738 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4739);
													mem_vec_4739 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4720);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_4721);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4722);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_4723);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4724);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_4725);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4726);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_4727);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4728);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_4729);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4730);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_4731);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4732);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_4733);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4734);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_4735);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4736);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_4737);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4738);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_4739);
									}
								}
}
