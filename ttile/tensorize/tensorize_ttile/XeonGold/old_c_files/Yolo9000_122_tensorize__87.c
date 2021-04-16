void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c309_p_0, cp_1, c309, f, fp_0, f386_p_0, f387_p_0, fp_1, f386_p_1, fp_2, f386, f387, h, hp_0, w, wp_0, x, xp_0, x316_p_0, xp_1, x316, y, yp_0;
IND_TYPE y219 = 0;
IND_TYPE x317 = 0;
IND_TYPE h198 = 0;
IND_TYPE w129 = 0;
IND_TYPE c310 = 0;
IND_TYPE f388 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4649 ,mem_vec_4650 ,mem_vec_4651 ,mem_vec_4652 ,mem_vec_4653 ,mem_vec_4654 ,mem_vec_4655 ,mem_vec_4656 ,mem_vec_4657 ,mem_vec_4658 ,mem_vec_4659 ,mem_vec_4660 ,mem_vec_4661 ,mem_vec_4662 ,mem_vec_4663 ,mem_vec_4664 ,mem_vec_4665 ,mem_vec_4666 ,mem_vec_4667 ,mem_vec_4668 ,mem_vec_4669 ,mem_vec_4670 ,mem_vec_4671 ,mem_vec_4672 ,mem_vec_4673 ,mem_vec_4674 ,mem_vec_4675 ,mem_vec_4676 ,mem_vec_4677 ,mem_vec_4678 ,mem_vec_4679 ,mem_vec_4680 ,mem_vec_4681 ,mem_vec_4682 ,mem_vec_4683 ,mem_vec_4684 ,mem_vec_4685 ,mem_vec_4686 ,mem_vec_4687 ,mem_vec_4688 ,mem_vec_4689 ,mem_vec_4690 ,mem_vec_4691 ,mem_vec_4692 ,mem_vec_4693 ,mem_vec_4694 ,mem_vec_4695 ,mem_vec_4696 ,mem_vec_4697 ,mem_vec_4698 ,mem_vec_4699 ,mem_vec_4700 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
f387 = 0;
f387_p_0 = 0;
f386 = 0;
f386_p_1 = 0;
x316 = 0;
x316_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c309 = 0;
c309_p_0 = 0;
							for (w = w129, wp_0 = 0;w < w129 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 64
								// T (x, 17) (17 / 1)
								for (x = x316, xp_1 = x316_p_0, xp_0 = 0;x < x316 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 64
									// T (h, 3) (3 / 1)
									for (h = h198, hp_0 = 0;h < h198 + 3;h += 1, hp_0 += 1){
												mem_vec_4673 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4674 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4675 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
												mem_vec_4676 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
												mem_vec_4677 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_4678 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_4679 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
												mem_vec_4680 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
												mem_vec_4681 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_4682 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_4683 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
												mem_vec_4684 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
												mem_vec_4685 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_4686 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_4687 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
												mem_vec_4688 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
												mem_vec_4689 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_4690 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_4691 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
												mem_vec_4692 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
												mem_vec_4693 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_4694 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_4695 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
												mem_vec_4696 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
												mem_vec_4697 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_4698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_4699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
												mem_vec_4700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
												// T (c, 32) (32 / 1)
												for (c = c309, cp_1 = c309_p_0, cp_0 = 0;c < c309 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4673);
													mem_vec_4673 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4674);
													mem_vec_4674 = vec_3;
													vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4675);
													mem_vec_4675 = vec_5;
													vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4676);
													mem_vec_4676 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);
													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4677);
													mem_vec_4677 = vec_9;
													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4678);
													mem_vec_4678 = vec_11;
													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4679);
													mem_vec_4679 = vec_12;
													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4680);
													mem_vec_4680 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4681);
													mem_vec_4681 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4682);
													mem_vec_4682 = vec_16;
													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4683);
													mem_vec_4683 = vec_17;
													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4684);
													mem_vec_4684 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4685);
													mem_vec_4685 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4686);
													mem_vec_4686 = vec_21;
													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4687);
													mem_vec_4687 = vec_22;
													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4688);
													mem_vec_4688 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);
													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4689);
													mem_vec_4689 = vec_24;
													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4690);
													mem_vec_4690 = vec_26;
													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4691);
													mem_vec_4691 = vec_27;
													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4692);
													mem_vec_4692 = vec_28;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4693);
													mem_vec_4693 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4694);
													mem_vec_4694 = vec_31;
													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4695);
													mem_vec_4695 = vec_32;
													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4696);
													mem_vec_4696 = vec_33;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4697);
													mem_vec_4697 = vec_34;
													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4698);
													mem_vec_4698 = vec_36;
													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4699);
													mem_vec_4699 = vec_37;
													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4700);
													mem_vec_4700 = vec_38;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4673);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4674);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_4675);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_4676);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4677);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4678);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_4679);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_4680);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4681);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4682);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_4683);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_4684);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4685);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4686);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_4687);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_4688);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4689);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4690);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_4691);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_4692);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4693);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4694);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_4695);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_4696);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4697);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4698);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_4699);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_4700);
									}
								}
							}
}
