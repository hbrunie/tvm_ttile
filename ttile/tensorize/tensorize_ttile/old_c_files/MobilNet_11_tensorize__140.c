
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 2), (Arg 14))]; T (1, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c744_p_0, cp_1, c744, h, hp_0, w, wp_0, x, xp_0, x992_p_0, x993_p_0, xp_1, x992_p_1, xp_2, x992, x993, y, yp_0;
IND_TYPE y496 = 0;
IND_TYPE x994 = 0;
IND_TYPE h476 = 0;
IND_TYPE w496 = 0;
IND_TYPE c745 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9420 ,mem_vec_9421 ,mem_vec_9422 ,mem_vec_9423 ,mem_vec_9424 ,mem_vec_9425 ,mem_vec_9426 ,mem_vec_9427 ,mem_vec_9428 ,mem_vec_9429 ,mem_vec_9430 ,mem_vec_9431 ,mem_vec_9432 ,mem_vec_9433 ,mem_vec_9434 ,mem_vec_9435 ,mem_vec_9436 ,mem_vec_9437 ,mem_vec_9438 ,mem_vec_9439 ,mem_vec_9440 ,mem_vec_9441 ,mem_vec_9442 ,mem_vec_9443 ,mem_vec_9444 ,mem_vec_9445 ,mem_vec_9446 ,mem_vec_9447 ,mem_vec_9448 ,mem_vec_9449 ,mem_vec_9450 ,mem_vec_9451 ,mem_vec_9452 ,mem_vec_9453 ,mem_vec_9454 ,mem_vec_9455 ,mem_vec_9456 ,mem_vec_9457 ,mem_vec_9458 ,mem_vec_9459 ,mem_vec_9460 ,mem_vec_9461 ,mem_vec_9462 ,mem_vec_9463 ,mem_vec_9464 ,mem_vec_9465 ,mem_vec_9466 ,mem_vec_9467 ,mem_vec_9468 ,mem_vec_9469 ,mem_vec_9470 ,mem_vec_9471 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
x993 = 0;
x993_p_0 = 0;
c744 = 0;
c744_p_0 = 0;
y = 0;
yp_0 = 0;
x992 = 0;
x992_p_1 = 0;
					for (h = h476, hp_0 = 0;h < h476 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w496, wp_0 = 0;w < w496 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x992, xp_2 = x992_p_1, xp_1 = x992_p_0, xp_0 = 0;x < x992 + 14;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_9421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_9422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_9423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_9424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_9425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_9426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_9427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_9428 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_9429 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_9430 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_9431 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_9432 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_9433 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_9434 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_9435 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_9436 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_9437 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_9438 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_9439 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_9440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_9441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_9442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_9443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c744, cp_1 = c744_p_0, cp_0 = 0;c < c744 + 32;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9420);
											mem_vec_9420 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9421);
											mem_vec_9421 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9422);
											mem_vec_9422 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9423);
											mem_vec_9423 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9424);
											mem_vec_9424 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9425);
											mem_vec_9425 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9426);
											mem_vec_9426 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9427);
											mem_vec_9427 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9428);
											mem_vec_9428 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9429);
											mem_vec_9429 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9430);
											mem_vec_9430 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9431);
											mem_vec_9431 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9432);
											mem_vec_9432 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9433);
											mem_vec_9433 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9434);
											mem_vec_9434 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9435);
											mem_vec_9435 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9436);
											mem_vec_9436 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9437);
											mem_vec_9437 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9438);
											mem_vec_9438 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9439);
											mem_vec_9439 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9440);
											mem_vec_9440 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9441);
											mem_vec_9441 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9442);
											mem_vec_9442 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9443);
											mem_vec_9443 = vec_37;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_9420);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_9421);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_9422);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_9423);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_9424);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_9425);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_9426);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_9427);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_9428);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_9429);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_9430);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_9431);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_9432);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_9433);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_9434);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_9435);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_9436);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_9437);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_9438);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_9439);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_9440);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_9441);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_9442);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_9443);
							}
						}
					}
}
