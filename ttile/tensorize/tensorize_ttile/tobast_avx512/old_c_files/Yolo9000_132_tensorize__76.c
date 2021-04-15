void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (16, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1110_p_0, cp_1, c1110, f, fp_0, x, xp_0, x1480_p_0, x1481_p_0, xp_1, x1480_p_1, xp_2, x1480, x1481, y, yp_0;
IND_TYPE y740 = 0;
IND_TYPE x1482 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1111 = 0;
IND_TYPE f740 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15520 ,mem_vec_15521 ,mem_vec_15522 ,mem_vec_15523 ,mem_vec_15524 ,mem_vec_15525 ,mem_vec_15526 ,mem_vec_15527 ,mem_vec_15528 ,mem_vec_15529 ,mem_vec_15530 ,mem_vec_15531 ,mem_vec_15532 ,mem_vec_15533 ,mem_vec_15534 ,mem_vec_15535 ,mem_vec_15536 ,mem_vec_15537 ,mem_vec_15538 ,mem_vec_15539 ,mem_vec_15540 ,mem_vec_15541 ,mem_vec_15542 ,mem_vec_15543 ,mem_vec_15544 ,mem_vec_15545 ,mem_vec_15546 ,mem_vec_15547 ,mem_vec_15548 ,mem_vec_15549 ,mem_vec_15550 ,mem_vec_15551 ,mem_vec_15552 ,mem_vec_15553 ,mem_vec_15554 ,mem_vec_15555 ,mem_vec_15556 ,mem_vec_15557 ,mem_vec_15558 ,mem_vec_15559 ,mem_vec_15560 ,mem_vec_15561 ,mem_vec_15562 ,mem_vec_15563 ,mem_vec_15564 ,mem_vec_15565 ,mem_vec_15566 ,mem_vec_15567 ,mem_vec_15568 ,mem_vec_15569 ,mem_vec_15570 ,mem_vec_15571 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
x1481 = 0;
x1481_p_0 = 0;
c1110 = 0;
c1110_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1480 = 0;
x1480_p_1 = 0;
						for (x = x1480, xp_2 = x1480_p_1, xp_1 = x1480_p_0, xp_0 = 0;x < x1480 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15544 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_15545 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_15546 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_15547 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_15548 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_15549 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_15550 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_15551 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_15552 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_15553 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_15554 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_15555 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_15556 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_15557 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_15558 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_15559 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_15560 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_15561 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_15562 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_15563 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_15564 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_15565 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_15566 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_15567 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_15568 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_15569 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_15570 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_15571 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1110, cp_1 = c1110_p_0, cp_0 = 0;c < c1110 + 32;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15544);
										mem_vec_15544 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15545);
										mem_vec_15545 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15546);
										mem_vec_15546 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15547);
										mem_vec_15547 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15548);
										mem_vec_15548 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15549);
										mem_vec_15549 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15550);
										mem_vec_15550 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15551);
										mem_vec_15551 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15552);
										mem_vec_15552 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15553);
										mem_vec_15553 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15554);
										mem_vec_15554 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15555);
										mem_vec_15555 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15556);
										mem_vec_15556 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15557);
										mem_vec_15557 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15558);
										mem_vec_15558 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15559);
										mem_vec_15559 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15560);
										mem_vec_15560 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15561);
										mem_vec_15561 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15562);
										mem_vec_15562 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15563);
										mem_vec_15563 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15564);
										mem_vec_15564 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15565);
										mem_vec_15565 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15566);
										mem_vec_15566 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15567);
										mem_vec_15567 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15568);
										mem_vec_15568 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15569);
										mem_vec_15569 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15570);
										mem_vec_15570 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15571);
										mem_vec_15571 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_15544);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_15545);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_15546);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_15547);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_15548);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_15549);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_15550);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_15551);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_15552);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_15553);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_15554);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_15555);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_15556);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_15557);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_15558);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_15559);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_15560);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_15561);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_15562);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_15563);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_15564);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_15565);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_15566);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_15567);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_15568);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_15569);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_15570);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_15571);
						}
}
