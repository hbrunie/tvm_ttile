
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))]; T (4, x);
  T (8, f); T (1, f)]
*/
IND_TYPE c, cp_0, c432_p_0, cp_1, c432, f, fp_0, f570_p_0, f571_p_0, fp_1, f570_p_1, fp_2, f570, f571, h, hp_0, w, wp_0, x, xp_0, x432_p_0, xp_1, x432, y, yp_0;
IND_TYPE y291 = 0;
IND_TYPE x433 = 0;
IND_TYPE h285 = 0;
IND_TYPE w265 = 0;
IND_TYPE c433 = 0;
IND_TYPE f572 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5548 ,mem_vec_5549 ,mem_vec_5550 ,mem_vec_5551 ,mem_vec_5552 ,mem_vec_5553 ,mem_vec_5554 ,mem_vec_5555 ,mem_vec_5556 ,mem_vec_5557 ,mem_vec_5558 ,mem_vec_5559 ,mem_vec_5560 ,mem_vec_5561 ,mem_vec_5562 ,mem_vec_5563 ,mem_vec_5564 ,mem_vec_5565 ,mem_vec_5566 ,mem_vec_5567 ,mem_vec_5568 ,mem_vec_5569 ,mem_vec_5570 ,mem_vec_5571 ,mem_vec_5572 ,mem_vec_5573 ,mem_vec_5574 ,mem_vec_5575 ,mem_vec_5576 ,mem_vec_5577 ,mem_vec_5578 ,mem_vec_5579 ,mem_vec_5580 ,mem_vec_5581 ,mem_vec_5582 ,mem_vec_5583 ,mem_vec_5584 ,mem_vec_5585 ,mem_vec_5586 ,mem_vec_5587 ,mem_vec_5588 ,mem_vec_5589 ,mem_vec_5590 ,mem_vec_5591 ,mem_vec_5592 ,mem_vec_5593 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
f571 = 0;
f571_p_0 = 0;
f570 = 0;
f570_p_1 = 0;
x432 = 0;
x432_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_2 = 0;
c432 = 0;
c432_p_0 = 0;
							for (w = w265, wp_0 = 0;w < w265 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x432, xp_1 = x432_p_0, xp_0 = 0;x < x432 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h285, hp_0 = 0;h < h285 + 3;h += 1, hp_0 += 1){
												mem_vec_5548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_5549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_5550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_5551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_5552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_5553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_5554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_5555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_5556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_5557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_5558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_5559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_5560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_5561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_5562 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_5563 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_5564 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_5565 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c432, cp_1 = c432_p_0, cp_0 = 0;c < c432 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5548);
													mem_vec_5548 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5549);
													mem_vec_5549 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5550);
													mem_vec_5550 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5551);
													mem_vec_5551 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5552);
													mem_vec_5552 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5553);
													mem_vec_5553 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5554);
													mem_vec_5554 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5555);
													mem_vec_5555 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5556);
													mem_vec_5556 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5557);
													mem_vec_5557 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5558);
													mem_vec_5558 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5559);
													mem_vec_5559 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5560);
													mem_vec_5560 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5561);
													mem_vec_5561 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5562);
													mem_vec_5562 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5563);
													mem_vec_5563 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5564);
													mem_vec_5564 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5565);
													mem_vec_5565 = vec_28;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5548);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5549);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5550);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5551);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5552);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5553);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5554);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5555);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5556);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5557);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5558);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5559);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5560);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5561);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5562);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5563);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5564);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5565);
									}
								}
							}
}
