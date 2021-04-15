
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (28, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 8), (Arg 9))]; T (16, c);
  T (4, x)]
*/
IND_TYPE c, cp_0, c748_p_0, cp_1, c748, h, hp_0, x, xp_0, x1000_p_0, x1001_p_0, xp_1, x1000_p_1, xp_2, x1000, x1001, y, yp_0;
IND_TYPE y500 = 0;
IND_TYPE x1002 = 0;
IND_TYPE h336 = 0;
IND_TYPE w = 0;
IND_TYPE c749 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7290 ,mem_vec_7291 ,mem_vec_7292 ,mem_vec_7293 ,mem_vec_7294 ,mem_vec_7295 ,mem_vec_7296 ,mem_vec_7297 ,mem_vec_7298 ,mem_vec_7299 ,mem_vec_7300 ,mem_vec_7301 ,mem_vec_7302 ,mem_vec_7303 ,mem_vec_7304 ,mem_vec_7305 ,mem_vec_7306 ,mem_vec_7307 ,mem_vec_7308 ,mem_vec_7309 ,mem_vec_7310 ,mem_vec_7311 ,mem_vec_7312 ,mem_vec_7313 ,mem_vec_7314 ,mem_vec_7315 ,mem_vec_7316 ,mem_vec_7317 ,mem_vec_7318 ,mem_vec_7319 ,mem_vec_7320 ,mem_vec_7321 ,mem_vec_7322 ,mem_vec_7323 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 4) (112 / 28)
x1001 = 0;
x1001_p_0 = 0;
c748 = 0;
c748_p_0 = 0;
y = 0;
yp_0 = 0;
x1000 = 0;
x1000_p_1 = 0;
					for (h = h336, hp_0 = 0;h < h336 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1000, xp_2 = x1000_p_1, xp_1 = x1000_p_0, xp_0 = 0;x < x1000 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7290 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_7291 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_7292 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_7293 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_7294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_7295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_7296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_7297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_7298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_7299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_7300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_7301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_7302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_7303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_7304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
									mem_vec_7305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c748, cp_1 = c748_p_0, cp_0 = 0;c < c748 + 2;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7290);
										mem_vec_7290 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7291);
										mem_vec_7291 = vec_3;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);
										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7292);
										mem_vec_7292 = vec_5;
										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7293);
										mem_vec_7293 = vec_7;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);
										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7294);
										mem_vec_7294 = vec_8;
										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7295);
										mem_vec_7295 = vec_10;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);
										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7296);
										mem_vec_7296 = vec_11;
										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7297);
										mem_vec_7297 = vec_13;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7298);
										mem_vec_7298 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7299);
										mem_vec_7299 = vec_16;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);
										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7300);
										mem_vec_7300 = vec_17;
										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7301);
										mem_vec_7301 = vec_19;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);
										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7302);
										mem_vec_7302 = vec_20;
										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7303);
										mem_vec_7303 = vec_22;
										scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7304);
										mem_vec_7304 = vec_23;
										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7305);
										mem_vec_7305 = vec_25;
										scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);
										vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7290);
										mem_vec_7290 = vec_26;
										vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
										vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7291);
										mem_vec_7291 = vec_29;
										scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
										vec_32 = _mm512_set1_ps(scal_9);
										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_7292);
										mem_vec_7292 = vec_31;
										vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_7293);
										mem_vec_7293 = vec_33;
										scal_10 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
										vec_35 = _mm512_set1_ps(scal_10);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_7294);
										mem_vec_7294 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_7295);
										mem_vec_7295 = vec_36;
										scal_11 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
										vec_38 = _mm512_set1_ps(scal_11);
										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_7296);
										mem_vec_7296 = vec_37;
										vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_7297);
										mem_vec_7297 = vec_39;
										scal_12 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
										vec_41 = _mm512_set1_ps(scal_12);
										vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_7298);
										mem_vec_7298 = vec_40;
										vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_7299);
										mem_vec_7299 = vec_42;
										scal_13 = input[strideA1 * (x + w + 1) + strideA2 * (y + 5 + h) + c];
										vec_44 = _mm512_set1_ps(scal_13);
										vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7300);
										mem_vec_7300 = vec_43;
										vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7301);
										mem_vec_7301 = vec_45;
										scal_14 = input[strideA1 * (x + w + 1) + strideA2 * (y + 6 + h) + c];
										vec_47 = _mm512_set1_ps(scal_14);
										vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_7302);
										mem_vec_7302 = vec_46;
										vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_7303);
										mem_vec_7303 = vec_48;
										scal_15 = input[strideA1 * (x + w + 1) + strideA2 * (y + 7 + h) + c];
										vec_50 = _mm512_set1_ps(scal_15);
										vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_7304);
										mem_vec_7304 = vec_49;
										vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_7305);
										mem_vec_7305 = vec_51;
										scal_16 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
										vec_53 = _mm512_set1_ps(scal_16);
										vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
										vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7290);
										mem_vec_7290 = vec_52;
										vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
										vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7291);
										mem_vec_7291 = vec_55;
										scal_17 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_17);
										vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7292);
										mem_vec_7292 = vec_57;
										vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7293);
										mem_vec_7293 = vec_59;
										scal_18 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
										vec_61 = _mm512_set1_ps(scal_18);
										vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_7294);
										mem_vec_7294 = vec_60;
										vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_7295);
										mem_vec_7295 = vec_62;
										scal_19 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
										vec_64 = _mm512_set1_ps(scal_19);
										vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_7296);
										mem_vec_7296 = vec_63;
										vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_7297);
										mem_vec_7297 = vec_65;
										scal_20 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
										vec_67 = _mm512_set1_ps(scal_20);
										vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_7298);
										mem_vec_7298 = vec_66;
										vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_7299);
										mem_vec_7299 = vec_68;
										scal_21 = input[strideA1 * (x + w + 2) + strideA2 * (y + 5 + h) + c];
										vec_70 = _mm512_set1_ps(scal_21);
										vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7300);
										mem_vec_7300 = vec_69;
										vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7301);
										mem_vec_7301 = vec_71;
										scal_22 = input[strideA1 * (x + w + 2) + strideA2 * (y + 6 + h) + c];
										vec_73 = _mm512_set1_ps(scal_22);
										vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_7302);
										mem_vec_7302 = vec_72;
										vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_7303);
										mem_vec_7303 = vec_74;
										scal_23 = input[strideA1 * (x + w + 2) + strideA2 * (y + 7 + h) + c];
										vec_76 = _mm512_set1_ps(scal_23);
										vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_7304);
										mem_vec_7304 = vec_75;
										vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_7305);
										mem_vec_7305 = vec_77;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_7290);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_7291);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_7292);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_7293);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_7294);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_7295);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_7296);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_7297);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_7298);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_7299);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_7300);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_7301);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_7302);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_7303);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_7304);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_7305);
						}
					}
}
