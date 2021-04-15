
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (512, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1424_p_0, c1425_p_0, cp_1, c1424_p_1, cp_2, c1424, c1425, f, fp_0, x, xp_0, x1068_p_0, xp_1, x1068, y, yp_0;
IND_TYPE y712 = 0;
IND_TYPE x1069 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1426 = 0;
IND_TYPE f712 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_12504 ,mem_vec_12505 ,mem_vec_12506 ,mem_vec_12507 ,mem_vec_12508 ,mem_vec_12509 ,mem_vec_12510 ,mem_vec_12511 ,mem_vec_12512 ,mem_vec_12513 ,mem_vec_12514 ,mem_vec_12515 ,mem_vec_12516 ,mem_vec_12517 ,mem_vec_12518 ,mem_vec_12519 ,mem_vec_12520 ,mem_vec_12521 ,mem_vec_12522 ,mem_vec_12523 ,mem_vec_12524 ,mem_vec_12525 ,mem_vec_12526 ,mem_vec_12527 ,mem_vec_12528 ,mem_vec_12529 ,mem_vec_12530 ,mem_vec_12531 ,mem_vec_12532 ,mem_vec_12533 ,mem_vec_12534 ,mem_vec_12535 ,mem_vec_12536 ,mem_vec_12537 ,mem_vec_12538 ,mem_vec_12539 ,mem_vec_12540 ,mem_vec_12541 ,mem_vec_12542 ,mem_vec_12543 ,mem_vec_12544 ,mem_vec_12545 ,mem_vec_12546 ,mem_vec_12547 ,mem_vec_12548 ,mem_vec_12549 ,mem_vec_12550 ,mem_vec_12551 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 1) (1024 / 1024)
c1425 = 0;
c1425_p_0 = 0;
y = 0;
yp_0 = 0;
x1068 = 0;
x1068_p_0 = 0;
f = 0;
fp_0 = 0;
c1424 = 0;
c1424_p_1 = 0;
						for (x = x1068, xp_1 = x1068_p_0, xp_0 = 0;x < x1068 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_12504 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_12505 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_12506 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_12507 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_12508 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_12509 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_12510 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_12511 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_12512 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_12513 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_12514 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_12515 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_12516 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_12517 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_12518 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_12519 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_12520 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_12521 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_12522 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_12523 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1424, cp_2 = c1424_p_1, cp_1 = c1424_p_0, cp_0 = 0;c < c1424 + 2;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12504);
										mem_vec_12504 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12505);
										mem_vec_12505 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12506);
										mem_vec_12506 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12507);
										mem_vec_12507 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12508);
										mem_vec_12508 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12509);
										mem_vec_12509 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12510);
										mem_vec_12510 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12511);
										mem_vec_12511 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12512);
										mem_vec_12512 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12513);
										mem_vec_12513 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12514);
										mem_vec_12514 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12515);
										mem_vec_12515 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12516);
										mem_vec_12516 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12517);
										mem_vec_12517 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12518);
										mem_vec_12518 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12519);
										mem_vec_12519 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12520);
										mem_vec_12520 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12521);
										mem_vec_12521 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12522);
										mem_vec_12522 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12523);
										mem_vec_12523 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12504);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12505);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_12506);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_12507);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12508);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12509);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_12510);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_12511);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12512);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12513);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_12514);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_12515);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12516);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12517);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_12518);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_12519);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_12520);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_12521);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_12522);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_12523);
						}
}
