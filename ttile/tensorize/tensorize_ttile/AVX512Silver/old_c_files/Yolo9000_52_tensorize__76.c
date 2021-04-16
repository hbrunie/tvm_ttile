void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (17, y);
  T (2, c); T (136, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c34_p_0, cp_1, c34, x, xp_0, x45_p_0, xp_1, x45, y, yp_0, y45_p_0, yp_1, y45;
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c35 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_572 ,mem_vec_573 ,mem_vec_574 ,mem_vec_575 ,mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y45 = 0;
y45_p_0 = 0;
x45 = 0;
x45_p_0 = 0;
c34 = 0;
c34_p_0 = 0;
y = 0;
yp_1 = 0;
					for (x = x45, xp_1 = x45_p_0, xp_0 = 0;x < x45 + 1;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_584 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_585 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_586 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_587 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_588 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_589 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_590 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_591 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_592 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_593 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_594 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_595 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								mem_vec_596 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_597 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_598 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
								mem_vec_599 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
								mem_vec_600 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_601 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_602 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
								mem_vec_603 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
								// T (c, 64) (64 / 1)
								for (c = c34, cp_1 = c34_p_0, cp_0 = 0;c < c34 + 64;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_584);
									mem_vec_584 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_585);
									mem_vec_585 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_586);
									mem_vec_586 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_587);
									mem_vec_587 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_588);
									mem_vec_588 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_589);
									mem_vec_589 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_590);
									mem_vec_590 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_591);
									mem_vec_591 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_592);
									mem_vec_592 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_593);
									mem_vec_593 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_594);
									mem_vec_594 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_595);
									mem_vec_595 = vec_18;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);
									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_596);
									mem_vec_596 = vec_19;
									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_597);
									mem_vec_597 = vec_21;
									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_598);
									mem_vec_598 = vec_22;
									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_599);
									mem_vec_599 = vec_23;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);
									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_600);
									mem_vec_600 = vec_24;
									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_601);
									mem_vec_601 = vec_26;
									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_602);
									mem_vec_602 = vec_27;
									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_603);
									mem_vec_603 = vec_28;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_584);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_585);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_586);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_587);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_588);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_589);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_590);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_591);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_592);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_593);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_594);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_595);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_596);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_597);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_598);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_599);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_600);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_601);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_602);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_603);
					}
}
