
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 1), (Arg 10))];
  T (4, f); T (2, c); T (2, f); T (8, c); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c858_p_0, c859_p_0, cp_1, c858_p_1, cp_2, c858, c859, f, fp_0, f834_p_0, f835_p_0, fp_1, f834_p_1, fp_2, f834, f835, h, hp_0, x, xp_0, x706_p_0, xp_1, x706, y, yp_0;
IND_TYPE y472 = 0;
IND_TYPE x707 = 0;
IND_TYPE h414 = 0;
IND_TYPE w = 0;
IND_TYPE c860 = 0;
IND_TYPE f836 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4380 ,mem_vec_4381 ,mem_vec_4382 ,mem_vec_4383 ,mem_vec_4384 ,mem_vec_4385 ,mem_vec_4386 ,mem_vec_4387 ,mem_vec_4388 ,mem_vec_4389 ,mem_vec_4390 ,mem_vec_4391 ,mem_vec_4392 ,mem_vec_4393 ,mem_vec_4394 ,mem_vec_4395 ,mem_vec_4396 ,mem_vec_4397 ,mem_vec_4398 ,mem_vec_4399 ,mem_vec_4400 ,mem_vec_4401 ,mem_vec_4402 ,mem_vec_4403 ,mem_vec_4404 ,mem_vec_4405 ,mem_vec_4406 ,mem_vec_4407 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
f835 = 0;
f835_p_0 = 0;
x706 = 0;
x706_p_0 = 0;
c859 = 0;
c859_p_0 = 0;
f834 = 0;
f834_p_1 = 0;
c858 = 0;
c858_p_1 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
								for (h = h414, hp_0 = 0;h < h414 + 3;h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
									// T (x, 7) (7 / 1)
									for (x = x706, xp_1 = x706_p_0, xp_0 = 0;x < x706 + 7;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4380 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_4381 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_4382 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_4383 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_4384 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_4385 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_4386 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_4387 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c858, cp_2 = c858_p_1, cp_1 = c858_p_0, cp_0 = 0;c < c858 + 16;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4380);
													mem_vec_4380 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4381);
													mem_vec_4381 = vec_3;
													scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4382);
													mem_vec_4382 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4383);
													mem_vec_4383 = vec_7;
													scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4384);
													mem_vec_4384 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4385);
													mem_vec_4385 = vec_10;
													scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4386);
													mem_vec_4386 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4387);
													mem_vec_4387 = vec_13;
													scal_4 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4380);
													mem_vec_4380 = vec_14;
													vec_18 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4381);
													mem_vec_4381 = vec_17;
													scal_5 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 1) + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);
													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_4382);
													mem_vec_4382 = vec_19;
													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_4383);
													mem_vec_4383 = vec_21;
													scal_6 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 2) + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_4384);
													mem_vec_4384 = vec_22;
													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_4385);
													mem_vec_4385 = vec_24;
													scal_7 = input[strideA1 * (2 * x + w + 1) + strideA2 * (2 * (y + 3) + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);
													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_4386);
													mem_vec_4386 = vec_25;
													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_4387);
													mem_vec_4387 = vec_27;
													scal_8 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4380);
													mem_vec_4380 = vec_28;
													vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4381);
													mem_vec_4381 = vec_31;
													scal_9 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 1) + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);
													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_4382);
													mem_vec_4382 = vec_33;
													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_4383);
													mem_vec_4383 = vec_35;
													scal_10 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 2) + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);
													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_4384);
													mem_vec_4384 = vec_36;
													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_4385);
													mem_vec_4385 = vec_38;
													scal_11 = input[strideA1 * (2 * x + w + 2) + strideA2 * (2 * (y + 3) + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);
													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_4386);
													mem_vec_4386 = vec_39;
													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_4387);
													mem_vec_4387 = vec_41;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_4380);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_4381);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_4382);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_4383);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_4384);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_4385);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_4386);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_4387);
									}
								}
}
