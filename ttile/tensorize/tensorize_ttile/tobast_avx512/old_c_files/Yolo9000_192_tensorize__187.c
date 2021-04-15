void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (128, c)]
*/
IND_TYPE c, cp_0, c1584_p_0, c1585_p_0, cp_1, c1584_p_1, cp_2, c1584, c1585, f, fp_0, x, xp_0, x1188_p_0, xp_1, x1188, y, yp_0;
IND_TYPE y792 = 0;
IND_TYPE x1189 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1586 = 0;
IND_TYPE f792 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14424 ,mem_vec_14425 ,mem_vec_14426 ,mem_vec_14427 ,mem_vec_14428 ,mem_vec_14429 ,mem_vec_14430 ,mem_vec_14431 ,mem_vec_14432 ,mem_vec_14433 ,mem_vec_14434 ,mem_vec_14435 ,mem_vec_14436 ,mem_vec_14437 ,mem_vec_14438 ,mem_vec_14439 ,mem_vec_14440 ,mem_vec_14441 ,mem_vec_14442 ,mem_vec_14443 ,mem_vec_14444 ,mem_vec_14445 ,mem_vec_14446 ,mem_vec_14447 ,mem_vec_14448 ,mem_vec_14449 ,mem_vec_14450 ,mem_vec_14451 ,mem_vec_14452 ,mem_vec_14453 ,mem_vec_14454 ,mem_vec_14455 ,mem_vec_14456 ,mem_vec_14457 ,mem_vec_14458 ,mem_vec_14459 ,mem_vec_14460 ,mem_vec_14461 ,mem_vec_14462 ,mem_vec_14463 ,mem_vec_14464 ,mem_vec_14465 ,mem_vec_14466 ,mem_vec_14467 ,mem_vec_14468 ,mem_vec_14469 ,mem_vec_14470 ,mem_vec_14471 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 128) (1024 / 8)
c1585 = 0;
c1585_p_0 = 0;
y = 0;
yp_0 = 0;
x1188 = 0;
x1188_p_0 = 0;
f = 0;
fp_0 = 0;
c1584 = 0;
c1584_p_1 = 0;
						for (x = x1188, xp_1 = x1188_p_0, xp_0 = 0;x < x1188 + 1;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_14445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_14446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_14447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_14448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_14449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_14450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_14451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_14452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_14453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_14454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_14455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_14456 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_14457 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_14458 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_14459 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_14460 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_14461 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_14462 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_14463 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_14464 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_14465 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_14466 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_14467 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_14468 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_14469 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_14470 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_14471 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c1584, cp_2 = c1584_p_1, cp_1 = c1584_p_0, cp_0 = 0;c < c1584 + 4;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14444);
										mem_vec_14444 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14445);
										mem_vec_14445 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14446);
										mem_vec_14446 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14447);
										mem_vec_14447 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14448);
										mem_vec_14448 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14449);
										mem_vec_14449 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14450);
										mem_vec_14450 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14451);
										mem_vec_14451 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14452);
										mem_vec_14452 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14453);
										mem_vec_14453 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14454);
										mem_vec_14454 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14455);
										mem_vec_14455 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14456);
										mem_vec_14456 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14457);
										mem_vec_14457 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14458);
										mem_vec_14458 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14459);
										mem_vec_14459 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14460);
										mem_vec_14460 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14461);
										mem_vec_14461 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14462);
										mem_vec_14462 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14463);
										mem_vec_14463 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14464);
										mem_vec_14464 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14465);
										mem_vec_14465 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14466);
										mem_vec_14466 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14467);
										mem_vec_14467 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14468);
										mem_vec_14468 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14469);
										mem_vec_14469 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14470);
										mem_vec_14470 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14471);
										mem_vec_14471 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_14444);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_14445);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_14446);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_14447);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_14448);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_14449);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_14450);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_14451);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_14452);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_14453);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_14454);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_14455);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_14456);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_14457);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_14458);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_14459);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_14460);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_14461);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_14462);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_14463);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_14464);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_14465);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_14466);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_14467);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_14468);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_14469);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_14470);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_14471);
						}
}
