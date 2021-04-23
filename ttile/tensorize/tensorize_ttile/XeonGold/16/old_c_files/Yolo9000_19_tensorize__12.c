
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (16, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, x, xp_0, y, yp_0, y54_p_0, yp_1, y54;
IND_TYPE y55 = 0;
IND_TYPE x36 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c55 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
y54 = 0;
y54_p_0 = 0;
	for (f = f36, fp_0 = 0;f < f36 + 512;f += 32, fp_0 += 32){
			for (y = y54, yp_1 = y54_p_0, yp_0 = 0;y < y54 + 8;y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 4) (1024 / 256)
				for (c54 = c55, c54_p_0 = 0;c54 < c55 + 1024;c54 += 256, c54_p_0 += 256){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x = x36, xp_0 = 0;x < x36 + 17;x += 1, xp_0 += 1){
								mem_vec_612 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_613 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_614 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_615 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_616 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_617 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_618 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_619 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_620 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_621 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_622 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_623 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_624 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_625 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_626 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_627 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
								// T (c, 256) (256 / 1)
								for (c = c54, cp_1 = c54_p_0, cp_0 = 0;c < c54 + 256;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_612);
									mem_vec_612 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_613);
									mem_vec_613 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_614);
									mem_vec_614 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_615);
									mem_vec_615 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_616);
									mem_vec_616 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_617);
									mem_vec_617 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_618);
									mem_vec_618 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_619);
									mem_vec_619 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_620);
									mem_vec_620 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_621);
									mem_vec_621 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_622);
									mem_vec_622 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_623);
									mem_vec_623 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_624);
									mem_vec_624 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_625);
									mem_vec_625 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_626);
									mem_vec_626 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_627);
									mem_vec_627 = vec_25;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_612);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_613);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_614);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_615);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_616);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_617);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_618);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_619);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_620);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_621);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_622);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_623);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_624);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_625);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_626);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_627);
					}
				}
			}
			for (y = y54 + 8, yp_1 = y54_p_0, yp_0 = 0;y < y54 + 8 + 9;y += 9, yp_1 += 9, yp_0 += 9){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 32
				// T (c, 4) (1024 / 256)
				for (c54 = c55, c54_p_0 = 0;c54 < c55 + 1024;c54 += 256, c54_p_0 += 256){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x = x36, xp_0 = 0;x < x36 + 17;x += 1, xp_0 += 1){
								mem_vec_628 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_629 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_630 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_631 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_632 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_633 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_634 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
								mem_vec_635 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
								mem_vec_636 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
								mem_vec_637 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
								mem_vec_638 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
								mem_vec_639 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
								mem_vec_640 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
								mem_vec_641 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
								mem_vec_642 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
								mem_vec_643 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
								mem_vec_644 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
								mem_vec_645 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
								// T (c, 256) (256 / 1)
								for (c = c54, cp_1 = c54_p_0, cp_0 = 0;c < c54 + 256;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_628);
									mem_vec_628 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_629);
									mem_vec_629 = vec_3;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);
									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_630);
									mem_vec_630 = vec_5;
									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_631);
									mem_vec_631 = vec_7;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);
									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_632);
									mem_vec_632 = vec_8;
									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_633);
									mem_vec_633 = vec_10;
									scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);
									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_634);
									mem_vec_634 = vec_11;
									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_635);
									mem_vec_635 = vec_13;
									scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_636);
									mem_vec_636 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_637);
									mem_vec_637 = vec_16;
									scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);
									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_638);
									mem_vec_638 = vec_17;
									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_639);
									mem_vec_639 = vec_19;
									scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);
									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_640);
									mem_vec_640 = vec_20;
									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_641);
									mem_vec_641 = vec_22;
									scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);
									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_642);
									mem_vec_642 = vec_23;
									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_643);
									mem_vec_643 = vec_25;
									scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);
									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_644);
									mem_vec_644 = vec_26;
									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_645);
									mem_vec_645 = vec_28;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_628);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_629);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_630);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_631);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_632);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_633);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_634);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_635);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_636);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_637);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_638);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_639);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_640);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_641);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_642);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_643);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_644);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_645);
					}
				}
			}
	}
}
