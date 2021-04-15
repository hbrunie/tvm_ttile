void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (4, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1104_p_0, cp_1, c1104, f, fp_0, x, xp_0, x1472_p_0, x1473_p_0, xp_1, x1472_p_1, xp_2, x1472, x1473, y, yp_0;
IND_TYPE y736 = 0;
IND_TYPE x1474 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1105 = 0;
IND_TYPE f736 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15416 ,mem_vec_15417 ,mem_vec_15418 ,mem_vec_15419 ,mem_vec_15420 ,mem_vec_15421 ,mem_vec_15422 ,mem_vec_15423 ,mem_vec_15424 ,mem_vec_15425 ,mem_vec_15426 ,mem_vec_15427 ,mem_vec_15428 ,mem_vec_15429 ,mem_vec_15430 ,mem_vec_15431 ,mem_vec_15432 ,mem_vec_15433 ,mem_vec_15434 ,mem_vec_15435 ,mem_vec_15436 ,mem_vec_15437 ,mem_vec_15438 ,mem_vec_15439 ,mem_vec_15440 ,mem_vec_15441 ,mem_vec_15442 ,mem_vec_15443 ,mem_vec_15444 ,mem_vec_15445 ,mem_vec_15446 ,mem_vec_15447 ,mem_vec_15448 ,mem_vec_15449 ,mem_vec_15450 ,mem_vec_15451 ,mem_vec_15452 ,mem_vec_15453 ,mem_vec_15454 ,mem_vec_15455 ,mem_vec_15456 ,mem_vec_15457 ,mem_vec_15458 ,mem_vec_15459 ,mem_vec_15460 ,mem_vec_15461 ,mem_vec_15462 ,mem_vec_15463 ,mem_vec_15464 ,mem_vec_15465 ,mem_vec_15466 ,mem_vec_15467 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
x1473 = 0;
x1473_p_0 = 0;
c1104 = 0;
c1104_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1472 = 0;
x1472_p_1 = 0;
						for (x = x1472, xp_2 = x1472_p_1, xp_1 = x1472_p_0, xp_0 = 0;x < x1472 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15440 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_15441 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_15442 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_15443 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_15444 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_15445 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_15446 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_15447 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_15448 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_15449 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_15450 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_15451 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_15452 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_15453 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_15454 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_15455 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_15456 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_15457 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_15458 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_15459 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_15460 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_15461 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_15462 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_15463 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_15464 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_15465 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_15466 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_15467 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c1104, cp_1 = c1104_p_0, cp_0 = 0;c < c1104 + 128;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15440);
										mem_vec_15440 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15441);
										mem_vec_15441 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15442);
										mem_vec_15442 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15443);
										mem_vec_15443 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15444);
										mem_vec_15444 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15445);
										mem_vec_15445 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15446);
										mem_vec_15446 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15447);
										mem_vec_15447 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15448);
										mem_vec_15448 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15449);
										mem_vec_15449 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15450);
										mem_vec_15450 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15451);
										mem_vec_15451 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15452);
										mem_vec_15452 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15453);
										mem_vec_15453 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15454);
										mem_vec_15454 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15455);
										mem_vec_15455 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15456);
										mem_vec_15456 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15457);
										mem_vec_15457 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15458);
										mem_vec_15458 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15459);
										mem_vec_15459 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15460);
										mem_vec_15460 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15461);
										mem_vec_15461 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15462);
										mem_vec_15462 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15463);
										mem_vec_15463 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15464);
										mem_vec_15464 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15465);
										mem_vec_15465 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15466);
										mem_vec_15466 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15467);
										mem_vec_15467 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_15440);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_15441);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_15442);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_15443);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_15444);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_15445);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_15446);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_15447);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_15448);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_15449);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_15450);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_15451);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_15452);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_15453);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_15454);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_15455);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_15456);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_15457);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_15458);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_15459);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_15460);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_15461);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_15462);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_15463);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_15464);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_15465);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_15466);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_15467);
						}
}
