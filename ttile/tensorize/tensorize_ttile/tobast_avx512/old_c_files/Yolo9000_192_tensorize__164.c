void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (256, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1152_p_0, c1153_p_0, cp_1, c1152_p_1, cp_2, c1152, c1153, f, fp_0, x, xp_0, x864_p_0, xp_1, x864, y, yp_0;
IND_TYPE y576 = 0;
IND_TYPE x865 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1154 = 0;
IND_TYPE f576 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_9672 ,mem_vec_9673 ,mem_vec_9674 ,mem_vec_9675 ,mem_vec_9676 ,mem_vec_9677 ,mem_vec_9678 ,mem_vec_9679 ,mem_vec_9680 ,mem_vec_9681 ,mem_vec_9682 ,mem_vec_9683 ,mem_vec_9684 ,mem_vec_9685 ,mem_vec_9686 ,mem_vec_9687 ,mem_vec_9688 ,mem_vec_9689 ,mem_vec_9690 ,mem_vec_9691 ,mem_vec_9692 ,mem_vec_9693 ,mem_vec_9694 ,mem_vec_9695 ,mem_vec_9696 ,mem_vec_9697 ,mem_vec_9698 ,mem_vec_9699 ,mem_vec_9700 ,mem_vec_9701 ,mem_vec_9702 ,mem_vec_9703 ,mem_vec_9704 ,mem_vec_9705 ,mem_vec_9706 ,mem_vec_9707 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 1) (1024 / 1024)
c1153 = 0;
c1153_p_0 = 0;
y = 0;
yp_0 = 0;
x864 = 0;
x864_p_0 = 0;
f = 0;
fp_0 = 0;
c1152 = 0;
c1152_p_1 = 0;
						for (x = x864, xp_1 = x864_p_0, xp_0 = 0;x < x864 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9688 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_9689 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_9690 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_9691 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_9692 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_9693 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_9694 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_9695 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_9696 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_9697 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_9698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_9699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_9700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_9701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_9702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_9703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_9704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_9705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_9706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_9707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1152, cp_2 = c1152_p_1, cp_1 = c1152_p_0, cp_0 = 0;c < c1152 + 4;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9688);
										mem_vec_9688 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9689);
										mem_vec_9689 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9690);
										mem_vec_9690 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9691);
										mem_vec_9691 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9692);
										mem_vec_9692 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9693);
										mem_vec_9693 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9694);
										mem_vec_9694 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9695);
										mem_vec_9695 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9696);
										mem_vec_9696 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9697);
										mem_vec_9697 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9698);
										mem_vec_9698 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9699);
										mem_vec_9699 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9700);
										mem_vec_9700 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9701);
										mem_vec_9701 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9702);
										mem_vec_9702 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9703);
										mem_vec_9703 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9704);
										mem_vec_9704 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9705);
										mem_vec_9705 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9706);
										mem_vec_9706 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9707);
										mem_vec_9707 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_9688);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_9689);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_9690);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_9691);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_9692);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_9693);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_9694);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_9695);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_9696);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_9697);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_9698);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_9699);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_9700);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_9701);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_9702);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_9703);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_9704);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_9705);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_9706);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_9707);
						}
}
