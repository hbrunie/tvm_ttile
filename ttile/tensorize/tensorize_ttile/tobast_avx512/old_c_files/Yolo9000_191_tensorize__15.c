
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (17, x); T (32, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1416_p_0, c1417_p_0, cp_1, c1416_p_1, cp_2, c1416, c1417, f, fp_0, x, xp_0, x1062_p_0, xp_1, x1062, y, yp_0;
IND_TYPE y708 = 0;
IND_TYPE x1063 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1418 = 0;
IND_TYPE f708 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_12408 ,mem_vec_12409 ,mem_vec_12410 ,mem_vec_12411 ,mem_vec_12412 ,mem_vec_12413 ,mem_vec_12414 ,mem_vec_12415 ,mem_vec_12416 ,mem_vec_12417 ,mem_vec_12418 ,mem_vec_12419 ,mem_vec_12420 ,mem_vec_12421 ,mem_vec_12422 ,mem_vec_12423 ,mem_vec_12424 ,mem_vec_12425 ,mem_vec_12426 ,mem_vec_12427 ,mem_vec_12428 ,mem_vec_12429 ,mem_vec_12430 ,mem_vec_12431 ,mem_vec_12432 ,mem_vec_12433 ,mem_vec_12434 ,mem_vec_12435 ,mem_vec_12436 ,mem_vec_12437 ,mem_vec_12438 ,mem_vec_12439 ,mem_vec_12440 ,mem_vec_12441 ,mem_vec_12442 ,mem_vec_12443 ,mem_vec_12444 ,mem_vec_12445 ,mem_vec_12446 ,mem_vec_12447 ,mem_vec_12448 ,mem_vec_12449 ,mem_vec_12450 ,mem_vec_12451 ,mem_vec_12452 ,mem_vec_12453 ,mem_vec_12454 ,mem_vec_12455 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 1) (1024 / 1024)
c1417 = 0;
c1417_p_0 = 0;
y = 0;
yp_0 = 0;
x1062 = 0;
x1062_p_0 = 0;
f = 0;
fp_0 = 0;
c1416 = 0;
c1416_p_1 = 0;
						for (x = x1062, xp_1 = x1062_p_0, xp_0 = 0;x < x1062 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_12408 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_12409 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_12410 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_12411 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_12412 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_12413 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_12414 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_12415 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_12416 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_12417 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_12418 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_12419 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_12420 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_12421 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_12422 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_12423 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_12424 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_12425 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_12426 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_12427 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1416, cp_2 = c1416_p_1, cp_1 = c1416_p_0, cp_0 = 0;c < c1416 + 32;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12408);
										mem_vec_12408 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12409);
										mem_vec_12409 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_12410);
										mem_vec_12410 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_12411);
										mem_vec_12411 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_12412);
										mem_vec_12412 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_12413);
										mem_vec_12413 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_12414);
										mem_vec_12414 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_12415);
										mem_vec_12415 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12416);
										mem_vec_12416 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12417);
										mem_vec_12417 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_12418);
										mem_vec_12418 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_12419);
										mem_vec_12419 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_12420);
										mem_vec_12420 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_12421);
										mem_vec_12421 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_12422);
										mem_vec_12422 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_12423);
										mem_vec_12423 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_12424);
										mem_vec_12424 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_12425);
										mem_vec_12425 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_12426);
										mem_vec_12426 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_12427);
										mem_vec_12427 = vec_28;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_12408);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_12409);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_12410);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_12411);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_12412);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_12413);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_12414);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_12415);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_12416);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_12417);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_12418);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_12419);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_12420);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_12421);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_12422);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_12423);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_12424);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_12425);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_12426);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_12427);
						}
}
