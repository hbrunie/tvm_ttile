
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (7, x); T (32, c);
  T (4, f); T (1, y); T (2, f)]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, f69_p_0, fp_1, f69, x, xp_0, y, yp_0;
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c70 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 1, w = 1, c = 256, f = 512
// T (f, 2) (512 / 256)
f69 = 0;
f69_p_0 = 0;
y = 0;
yp_0 = 0;
f = 0;
fp_1 = 0;
c69 = 0;
c69_p_0 = 0;
				for (x = x46, xp_0 = 0;x < x46 + 7;x += 1, xp_0 += 1){
							mem_vec_644 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
							mem_vec_645 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
							mem_vec_646 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
							mem_vec_647 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
							mem_vec_648 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
							mem_vec_649 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
							mem_vec_650 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
							mem_vec_651 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
							mem_vec_652 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
							mem_vec_653 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
							mem_vec_654 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
							mem_vec_655 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
							mem_vec_656 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
							mem_vec_657 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
							mem_vec_658 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
							mem_vec_659 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
							mem_vec_660 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
							mem_vec_661 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
							mem_vec_662 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
							mem_vec_663 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
							mem_vec_664 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
							mem_vec_665 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
							mem_vec_666 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
							mem_vec_667 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
							mem_vec_668 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
							mem_vec_669 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
							mem_vec_670 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
							mem_vec_671 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
							// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
							// T (c, 8) (8 / 1)
							for (c = c69, cp_1 = c69_p_0, cp_0 = 0;c < c69 + 8;c += 1, cp_1 += 1, cp_0 += 1){
								scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_644);
								mem_vec_644 = vec_0;
								vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_645);
								mem_vec_645 = vec_3;
								vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
								vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_646);
								mem_vec_646 = vec_5;
								vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
								vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_647);
								mem_vec_647 = vec_7;
								scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
								vec_10 = _mm512_set1_ps(scal_1);
								vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_648);
								mem_vec_648 = vec_9;
								vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_649);
								mem_vec_649 = vec_11;
								vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_650);
								mem_vec_650 = vec_12;
								vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_651);
								mem_vec_651 = vec_13;
								scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
								vec_15 = _mm512_set1_ps(scal_2);
								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_652);
								mem_vec_652 = vec_14;
								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_653);
								mem_vec_653 = vec_16;
								vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_654);
								mem_vec_654 = vec_17;
								vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_655);
								mem_vec_655 = vec_18;
								scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
								vec_20 = _mm512_set1_ps(scal_3);
								vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_656);
								mem_vec_656 = vec_19;
								vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_657);
								mem_vec_657 = vec_21;
								vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_658);
								mem_vec_658 = vec_22;
								vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_659);
								mem_vec_659 = vec_23;
								scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
								vec_25 = _mm512_set1_ps(scal_4);
								vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_660);
								mem_vec_660 = vec_24;
								vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_661);
								mem_vec_661 = vec_26;
								vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_662);
								mem_vec_662 = vec_27;
								vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_663);
								mem_vec_663 = vec_28;
								scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
								vec_30 = _mm512_set1_ps(scal_5);
								vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_664);
								mem_vec_664 = vec_29;
								vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_665);
								mem_vec_665 = vec_31;
								vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_666);
								mem_vec_666 = vec_32;
								vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_667);
								mem_vec_667 = vec_33;
								scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
								vec_35 = _mm512_set1_ps(scal_6);
								vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_668);
								mem_vec_668 = vec_34;
								vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_669);
								mem_vec_669 = vec_36;
								vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_670);
								mem_vec_670 = vec_37;
								vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_671);
								mem_vec_671 = vec_38;
							}
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_644);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_645);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_646);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_647);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_648);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_649);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_650);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_651);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_652);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_653);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_654);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_655);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_656);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_657);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_658);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_659);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_660);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_661);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_662);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_663);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_664);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_665);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_666);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_667);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_668);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_669);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_670);
						_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_671);
				}
}
