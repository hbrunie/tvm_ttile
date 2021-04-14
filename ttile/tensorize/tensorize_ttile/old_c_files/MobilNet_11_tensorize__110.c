
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 11), (Arg 9)); ((Iter 1), (Arg 13))]; T (8, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c444_p_0, cp_1, c444, h, hp_0, w, wp_0, x, xp_0, x592_p_0, x593_p_0, xp_1, x592_p_1, xp_2, x592, x593, y, yp_0;
IND_TYPE y296 = 0;
IND_TYPE x594 = 0;
IND_TYPE h276 = 0;
IND_TYPE w296 = 0;
IND_TYPE c445 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4696 ,mem_vec_4697 ,mem_vec_4698 ,mem_vec_4699 ,mem_vec_4700 ,mem_vec_4701 ,mem_vec_4702 ,mem_vec_4703 ,mem_vec_4704 ,mem_vec_4705 ,mem_vec_4706 ,mem_vec_4707 ,mem_vec_4708 ,mem_vec_4709 ,mem_vec_4710 ,mem_vec_4711 ,mem_vec_4712 ,mem_vec_4713 ,mem_vec_4714 ,mem_vec_4715 ,mem_vec_4716 ,mem_vec_4717 ,mem_vec_4718 ,mem_vec_4719 ,mem_vec_4720 ,mem_vec_4721 ,mem_vec_4722 ,mem_vec_4723 ,mem_vec_4724 ,mem_vec_4725 ,mem_vec_4726 ,mem_vec_4727 ,mem_vec_4728 ,mem_vec_4729 ,mem_vec_4730 ,mem_vec_4731 ,mem_vec_4732 ,mem_vec_4733 ,mem_vec_4734 ,mem_vec_4735 ,mem_vec_4736 ,mem_vec_4737 ,mem_vec_4738 ,mem_vec_4739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
x593 = 0;
x593_p_0 = 0;
c444 = 0;
c444_p_0 = 0;
y = 0;
yp_0 = 0;
x592 = 0;
x592_p_1 = 0;
					for (h = h276, hp_0 = 0;h < h276 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 4, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w296, wp_0 = 0;w < w296 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 1, c = 4, f = 32
							// T (x, 4) (4 / 1)
							for (x = x592, xp_2 = x592_p_1, xp_1 = x592_p_0, xp_0 = 0;x < x592 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4696 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_4697 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_4698 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_4699 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_4700 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_4701 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_4702 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_4703 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_4704 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_4705 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_4706 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_4707 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_4708 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_4709 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_4710 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_4711 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_4712 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_4713 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c444, cp_1 = c444_p_0, cp_0 = 0;c < c444 + 4;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4696);
											mem_vec_4696 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4697);
											mem_vec_4697 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4698);
											mem_vec_4698 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4699);
											mem_vec_4699 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4700);
											mem_vec_4700 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4701);
											mem_vec_4701 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4702);
											mem_vec_4702 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4703);
											mem_vec_4703 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4704);
											mem_vec_4704 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4705);
											mem_vec_4705 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4706);
											mem_vec_4706 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4707);
											mem_vec_4707 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4708);
											mem_vec_4708 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4709);
											mem_vec_4709 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4710);
											mem_vec_4710 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4711);
											mem_vec_4711 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4712);
											mem_vec_4712 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4713);
											mem_vec_4713 = vec_28;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4696);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4697);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4698);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4699);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4700);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4701);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4702);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4703);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_4704);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_4705);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_4706);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_4707);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_4708);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_4709);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_4710);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_4711);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_4712);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_4713);
							}
						}
					}
}
