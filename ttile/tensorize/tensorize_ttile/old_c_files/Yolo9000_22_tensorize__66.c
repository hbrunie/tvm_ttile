void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (136, x);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (2, f);
  T (32, c); T (1, x); T (1, x)]
*/
IND_TYPE c, cp_0, c876_p_0, cp_1, c876, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1460_p_0, x1461_p_0, x1462_p_0, xp_1, x1460_p_1, x1461_p_1, xp_2, x1460_p_2, xp_3, x1460, x1461, x1462, y, yp_0;
IND_TYPE y584 = 0;
IND_TYPE x1463 = 0;
IND_TYPE h584 = 0;
IND_TYPE w444 = 0;
IND_TYPE c877 = 0;
IND_TYPE f444 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4672 ,mem_vec_4673 ,mem_vec_4674 ,mem_vec_4675 ,mem_vec_4676 ,mem_vec_4677 ,mem_vec_4678 ,mem_vec_4679 ,mem_vec_4680 ,mem_vec_4681 ,mem_vec_4682 ,mem_vec_4683 ,mem_vec_4684 ,mem_vec_4685 ,mem_vec_4686 ,mem_vec_4687 ,mem_vec_4688 ,mem_vec_4689 ,mem_vec_4690 ,mem_vec_4691 ,mem_vec_4692 ,mem_vec_4693 ,mem_vec_4694 ,mem_vec_4695 ,mem_vec_4696 ,mem_vec_4697 ,mem_vec_4698 ,mem_vec_4699 ,mem_vec_4700 ,mem_vec_4701 ,mem_vec_4702 ,mem_vec_4703 ,mem_vec_4704 ,mem_vec_4705 ,mem_vec_4706 ,mem_vec_4707 ,mem_vec_4708 ,mem_vec_4709 ,mem_vec_4710 ,mem_vec_4711 ,mem_vec_4712 ,mem_vec_4713 ,mem_vec_4714 ,mem_vec_4715 ,mem_vec_4716 ,mem_vec_4717 ,mem_vec_4718 ,mem_vec_4719 ,mem_vec_4720 ,mem_vec_4721 ,mem_vec_4722 ,mem_vec_4723 ,mem_vec_4724 ,mem_vec_4725 ,mem_vec_4726 ,mem_vec_4727 ,mem_vec_4728 ,mem_vec_4729 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
x1462 = 0;
x1462_p_0 = 0;
x1461 = 0;
x1461_p_1 = 0;
c876 = 0;
c876_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1460 = 0;
x1460_p_2 = 0;
							for (h = h584, hp_0 = 0;h < h584 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w444, wp_0 = 0;w < w444 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 1, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1460, xp_3 = x1460_p_2, xp_2 = x1460_p_1, xp_1 = x1460_p_0, xp_0 = 0;x < x1460 + 2;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_4703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_4704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_4705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_4706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_4707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_4708 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_4709 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_4710 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_4711 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_4712 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_4713 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_4714 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_4715 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_4716 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_4717 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_4718 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_4719 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_4720 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_4721 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_4722 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_4723 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_4724 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_4725 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												mem_vec_4726 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
												mem_vec_4727 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
												mem_vec_4728 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
												mem_vec_4729 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c876, cp_1 = c876_p_0, cp_0 = 0;c < c876 + 1;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4700);
													mem_vec_4700 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4701);
													mem_vec_4701 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4702);
													mem_vec_4702 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4703);
													mem_vec_4703 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4704);
													mem_vec_4704 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4705);
													mem_vec_4705 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4706);
													mem_vec_4706 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4707);
													mem_vec_4707 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4708);
													mem_vec_4708 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4709);
													mem_vec_4709 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4710);
													mem_vec_4710 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4711);
													mem_vec_4711 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4712);
													mem_vec_4712 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4713);
													mem_vec_4713 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4714);
													mem_vec_4714 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4715);
													mem_vec_4715 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4716);
													mem_vec_4716 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4717);
													mem_vec_4717 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4718);
													mem_vec_4718 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4719);
													mem_vec_4719 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4720);
													mem_vec_4720 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4721);
													mem_vec_4721 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4722);
													mem_vec_4722 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4723);
													mem_vec_4723 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4724);
													mem_vec_4724 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4725);
													mem_vec_4725 = vec_40;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);
													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_4726);
													mem_vec_4726 = vec_41;
													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_4727);
													mem_vec_4727 = vec_43;
													scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);
													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_4728);
													mem_vec_4728 = vec_44;
													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_4729);
													mem_vec_4729 = vec_46;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4700);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4701);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4702);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4703);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4704);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4705);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4706);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4707);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4708);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4709);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4710);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4711);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4712);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4713);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4714);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4715);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4716);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4717);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_4718);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_4719);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_4720);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_4721);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_4722);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_4723);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_4724);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_4725);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_4726);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_4727);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_4728);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_4729);
									}
								}
							}
}
