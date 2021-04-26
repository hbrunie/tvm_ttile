
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]; T (16, f);
  T (8, c); T (1, c)]
*/
IND_TYPE c, cp_0, c770_p_0, c771_p_0, c772_p_0, cp_1, c770_p_1, c771_p_1, cp_2, c770_p_2, cp_3, c770, c771, c772, f, fp_0, w, wp_0, x, xp_0, y, yp_0;
IND_TYPE y308 = 0;
IND_TYPE x308 = 0;
IND_TYPE h = 0;
IND_TYPE w254 = 0;
IND_TYPE c773 = 0;
IND_TYPE f308 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6278 ,mem_vec_6279 ,mem_vec_6280 ,mem_vec_6281 ,mem_vec_6282 ,mem_vec_6283 ,mem_vec_6284 ,mem_vec_6285 ,mem_vec_6286 ,mem_vec_6287 ,mem_vec_6288 ,mem_vec_6289 ,mem_vec_6290 ,mem_vec_6291 ,mem_vec_6292 ,mem_vec_6293 ,mem_vec_6294 ,mem_vec_6295 ,mem_vec_6296 ,mem_vec_6297 ,mem_vec_6298 ,mem_vec_6299 ,mem_vec_6300 ,mem_vec_6301 ,mem_vec_6302 ,mem_vec_6303 ,mem_vec_6304 ,mem_vec_6305 ,mem_vec_6306 ,mem_vec_6307 ,mem_vec_6308 ,mem_vec_6309 ,mem_vec_6310 ,mem_vec_6311 ,mem_vec_6312 ,mem_vec_6313 ,mem_vec_6314 ,mem_vec_6315 ,mem_vec_6316 ,mem_vec_6317 ,mem_vec_6318 ,mem_vec_6319 ,mem_vec_6320 ,mem_vec_6321 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
c772 = 0;
c772_p_0 = 0;
c771 = 0;
c771_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
c770 = 0;
c770_p_2 = 0;
x = 0;
xp_0 = 0;
							for (w = w254, wp_0 = 0;w < w254 + 3;w += 1, wp_0 += 1){
										mem_vec_6278 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_6279 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_6280 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_6281 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_6282 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_6283 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_6284 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_6285 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_6286 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_6287 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_6288 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_6289 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_6290 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_6291 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_6292 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_6293 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_6294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_6295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_6296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_6297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c770, cp_3 = c770_p_2, cp_2 = c770_p_1, cp_1 = c770_p_0, cp_0 = 0;c < c770 + 16;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6278);
											mem_vec_6278 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6279);
											mem_vec_6279 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6280);
											mem_vec_6280 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6281);
											mem_vec_6281 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6282);
											mem_vec_6282 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6283);
											mem_vec_6283 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6284);
											mem_vec_6284 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6285);
											mem_vec_6285 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6286);
											mem_vec_6286 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6287);
											mem_vec_6287 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6288);
											mem_vec_6288 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6289);
											mem_vec_6289 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6290);
											mem_vec_6290 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6291);
											mem_vec_6291 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6292);
											mem_vec_6292 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6293);
											mem_vec_6293 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6294);
											mem_vec_6294 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6295);
											mem_vec_6295 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6296);
											mem_vec_6296 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6297);
											mem_vec_6297 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f]);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6278);
											mem_vec_6278 = vec_29;
											vec_33 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 16]);
											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6279);
											mem_vec_6279 = vec_32;
											vec_35 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 32]);
											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_6280);
											mem_vec_6280 = vec_34;
											vec_37 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 1) + strideW3 * c + f + 48]);
											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_6281);
											mem_vec_6281 = vec_36;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_6282);
											mem_vec_6282 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_6283);
											mem_vec_6283 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_6284);
											mem_vec_6284 = vec_41;
											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_6285);
											mem_vec_6285 = vec_42;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6286);
											mem_vec_6286 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6287);
											mem_vec_6287 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_6288);
											mem_vec_6288 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_6289);
											mem_vec_6289 = vec_47;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_6290);
											mem_vec_6290 = vec_48;
											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_6291);
											mem_vec_6291 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_6292);
											mem_vec_6292 = vec_51;
											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_6293);
											mem_vec_6293 = vec_52;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_6294);
											mem_vec_6294 = vec_53;
											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_6295);
											mem_vec_6295 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_6296);
											mem_vec_6296 = vec_56;
											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_6297);
											mem_vec_6297 = vec_57;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f]);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6278);
											mem_vec_6278 = vec_58;
											vec_62 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 16]);
											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6279);
											mem_vec_6279 = vec_61;
											vec_64 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 32]);
											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_6280);
											mem_vec_6280 = vec_63;
											vec_66 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * (h + 2) + strideW3 * c + f + 48]);
											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_6281);
											mem_vec_6281 = vec_65;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_6282);
											mem_vec_6282 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_6283);
											mem_vec_6283 = vec_69;
											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_6284);
											mem_vec_6284 = vec_70;
											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_6285);
											mem_vec_6285 = vec_71;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);
											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6286);
											mem_vec_6286 = vec_72;
											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6287);
											mem_vec_6287 = vec_74;
											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_6288);
											mem_vec_6288 = vec_75;
											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_6289);
											mem_vec_6289 = vec_76;
											scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_6290);
											mem_vec_6290 = vec_77;
											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_6291);
											mem_vec_6291 = vec_79;
											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_6292);
											mem_vec_6292 = vec_80;
											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_6293);
											mem_vec_6293 = vec_81;
											scal_14 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);
											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_6294);
											mem_vec_6294 = vec_82;
											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_6295);
											mem_vec_6295 = vec_84;
											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_6296);
											mem_vec_6296 = vec_85;
											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_6297);
											mem_vec_6297 = vec_86;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_6278);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_6279);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_6280);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_6281);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_6282);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_6283);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_6284);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_6285);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_6286);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_6287);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_6288);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_6289);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_6290);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_6291);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_6292);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_6293);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_6294);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_6295);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_6296);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_6297);
							}
}
