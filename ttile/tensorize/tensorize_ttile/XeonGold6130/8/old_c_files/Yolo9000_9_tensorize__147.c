
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (4, x); T (4, c);
  T (4, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]; T (1, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c354_p_0, cp_1, c354, f, fp_0, x, xp_0, x472_p_0, x473_p_0, xp_1, x472_p_1, xp_2, x472, x473, y, yp_0, y354_p_0, yp_1, y354;
IND_TYPE y355 = 0;
IND_TYPE x474 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c355 = 0;
IND_TYPE f236 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5592 ,mem_vec_5593 ,mem_vec_5594 ,mem_vec_5595 ,mem_vec_5596 ,mem_vec_5597 ,mem_vec_5598 ,mem_vec_5599 ,mem_vec_5600 ,mem_vec_5601 ,mem_vec_5602 ,mem_vec_5603 ,mem_vec_5604 ,mem_vec_5605 ,mem_vec_5606 ,mem_vec_5607 ,mem_vec_5608 ,mem_vec_5609 ,mem_vec_5610 ,mem_vec_5611 ,mem_vec_5612 ,mem_vec_5613 ,mem_vec_5614 ,mem_vec_5615 ,mem_vec_5616 ,mem_vec_5617 ,mem_vec_5618 ,mem_vec_5619 ,mem_vec_5620 ,mem_vec_5621 ,mem_vec_5622 ,mem_vec_5623 ,mem_vec_5624 ,mem_vec_5625 ,mem_vec_5626 ,mem_vec_5627 ,mem_vec_5628 ,mem_vec_5629 ,mem_vec_5630 ,mem_vec_5631 ,mem_vec_5632 ,mem_vec_5633 ,mem_vec_5634 ,mem_vec_5635 ,mem_vec_5636 ,mem_vec_5637 ,mem_vec_5638 ,mem_vec_5639 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
y354 = 0;
y354_p_0 = 0;
	for (x473 = x474, x473_p_0 = 0;x473 < x474 + 68;x473 += 68, x473_p_0 += 68){
			for (y = y354, yp_1 = y354_p_0, yp_0 = 0;y < y354 + 20;y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 17) (68 / 4)
				for (x472 = x473, x472_p_1 = x473_p_0, x472_p_0 = 0;x472 < x473 + 68;x472 += 4, x472_p_1 += 4, x472_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f236, fp_0 = 0;f < f236 + 128;f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 4) (256 / 64)
						for (c354 = c355, c354_p_0 = 0;c354 < c355 + 256;c354 += 64, c354_p_0 += 64){
							// y = ph_y, x = 4, h = 1, w = 1, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x472, xp_2 = x472_p_1, xp_1 = x472_p_0, xp_0 = 0;x < x472 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5592 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5593 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5594 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5595 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5596 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5597 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5598 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5599 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5600 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5601 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5602 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5603 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5604 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5605 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_5606 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_5607 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_5608 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_5609 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_5610 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_5611 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c354, cp_1 = c354_p_0, cp_0 = 0;c < c354 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5592);
											mem_vec_5592 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5593);
											mem_vec_5593 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5594);
											mem_vec_5594 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5595);
											mem_vec_5595 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5596);
											mem_vec_5596 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5597);
											mem_vec_5597 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5598);
											mem_vec_5598 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5599);
											mem_vec_5599 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5600);
											mem_vec_5600 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5601);
											mem_vec_5601 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5602);
											mem_vec_5602 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5603);
											mem_vec_5603 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5604);
											mem_vec_5604 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5605);
											mem_vec_5605 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5606);
											mem_vec_5606 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5607);
											mem_vec_5607 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5608);
											mem_vec_5608 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5609);
											mem_vec_5609 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5610);
											mem_vec_5610 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5611);
											mem_vec_5611 = vec_31;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5592);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5593);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5594);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5595);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5596);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5597);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5598);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5599);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5600);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5601);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5602);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5603);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5604);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5605);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5606);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5607);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5608);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5609);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5610);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5611);
							}
						}
					}
				}
			}
			for (y = y354 + 20, yp_1 = y354_p_0, yp_0 = 0;y < y354 + 20 + 14;y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 17) (68 / 4)
				for (x472 = x473, x472_p_1 = x473_p_0, x472_p_0 = 0;x472 < x473 + 68;x472 += 4, x472_p_1 += 4, x472_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f236, fp_0 = 0;f < f236 + 128;f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 4) (256 / 64)
						for (c354 = c355, c354_p_0 = 0;c354 < c355 + 256;c354 += 64, c354_p_0 += 64){
							// y = ph_y, x = 4, h = 1, w = 1, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x472, xp_2 = x472_p_1, xp_1 = x472_p_0, xp_0 = 0;x < x472 + 4;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5612 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_5613 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_5614 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_5615 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_5616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_5617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_5618 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_5619 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_5620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_5621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_5622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_5623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_5624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_5625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_5626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_5627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_5628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_5629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_5630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_5631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_5632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_5633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_5634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_5635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										mem_vec_5636 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										mem_vec_5637 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
										mem_vec_5638 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
										mem_vec_5639 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c354, cp_1 = c354_p_0, cp_0 = 0;c < c354 + 64;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5612);
											mem_vec_5612 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5613);
											mem_vec_5613 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5614);
											mem_vec_5614 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5615);
											mem_vec_5615 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5616);
											mem_vec_5616 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5617);
											mem_vec_5617 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5618);
											mem_vec_5618 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5619);
											mem_vec_5619 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5620);
											mem_vec_5620 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5621);
											mem_vec_5621 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5622);
											mem_vec_5622 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5623);
											mem_vec_5623 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5624);
											mem_vec_5624 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5625);
											mem_vec_5625 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5626);
											mem_vec_5626 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5627);
											mem_vec_5627 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5628);
											mem_vec_5628 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5629);
											mem_vec_5629 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5630);
											mem_vec_5630 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5631);
											mem_vec_5631 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5632);
											mem_vec_5632 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5633);
											mem_vec_5633 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5634);
											mem_vec_5634 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5635);
											mem_vec_5635 = vec_37;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5636);
											mem_vec_5636 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5637);
											mem_vec_5637 = vec_40;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);
											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5638);
											mem_vec_5638 = vec_41;
											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5639);
											mem_vec_5639 = vec_43;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_5612);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_5613);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_5614);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_5615);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_5616);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_5617);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_5618);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_5619);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_5620);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_5621);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_5622);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_5623);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_5624);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_5625);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_5626);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_5627);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_5628);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_5629);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_5630);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_5631);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_5632);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_5633);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_5634);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_5635);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_5636);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_5637);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_5638);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_5639);
							}
						}
					}
				}
			}
	}
}
