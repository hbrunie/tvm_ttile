
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (17, x); T (8, c);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (16, f);
  T (1, c); T (2, c)]
*/
IND_TYPE c, cp_0, c280_p_0, c281_p_0, c282_p_0, cp_1, c280_p_1, c281_p_1, cp_2, c280_p_2, cp_3, c280, c281, c282, f, fp_0, h, hp_0, x, xp_0, y, yp_0;
IND_TYPE y112 = 0;
IND_TYPE x112 = 0;
IND_TYPE h94 = 0;
IND_TYPE w = 0;
IND_TYPE c283 = 0;
IND_TYPE f112 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2294 ,mem_vec_2295 ,mem_vec_2296 ,mem_vec_2297 ,mem_vec_2298 ,mem_vec_2299 ,mem_vec_2300 ,mem_vec_2301 ,mem_vec_2302 ,mem_vec_2303 ,mem_vec_2304 ,mem_vec_2305 ,mem_vec_2306 ,mem_vec_2307 ,mem_vec_2308 ,mem_vec_2309 ,mem_vec_2310 ,mem_vec_2311 ,mem_vec_2312 ,mem_vec_2313 ,mem_vec_2314 ,mem_vec_2315 ,mem_vec_2316 ,mem_vec_2317 ,mem_vec_2318 ,mem_vec_2319 ,mem_vec_2320 ,mem_vec_2321 ,mem_vec_2322 ,mem_vec_2323 ,mem_vec_2324 ,mem_vec_2325 ,mem_vec_2326 ,mem_vec_2327 ,mem_vec_2328 ,mem_vec_2329 ,mem_vec_2330 ,mem_vec_2331 ,mem_vec_2332 ,mem_vec_2333 ,mem_vec_2334 ,mem_vec_2335 ,mem_vec_2336 ,mem_vec_2337 ,mem_vec_2338 ,mem_vec_2339 ,mem_vec_2340 ,mem_vec_2341 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
c282 = 0;
c282_p_0 = 0;
c281 = 0;
c281_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
c280 = 0;
c280_p_2 = 0;
x = 0;
xp_0 = 0;
							for (h = h94, hp_0 = 0;h < h94 + 3;h += 1, hp_0 += 1){
										mem_vec_2294 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_2295 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_2296 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_2297 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_2298 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_2299 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_2300 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_2301 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_2302 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_2303 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_2304 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_2305 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_2306 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_2307 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_2308 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_2309 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_2310 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_2311 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_2312 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_2313 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c280, cp_3 = c280_p_2, cp_2 = c280_p_1, cp_1 = c280_p_0, cp_0 = 0;c < c280 + 32;c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2294);
											mem_vec_2294 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2295);
											mem_vec_2295 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2296);
											mem_vec_2296 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2297);
											mem_vec_2297 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2298);
											mem_vec_2298 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2299);
											mem_vec_2299 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2300);
											mem_vec_2300 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2301);
											mem_vec_2301 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2302);
											mem_vec_2302 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2303);
											mem_vec_2303 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2304);
											mem_vec_2304 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2305);
											mem_vec_2305 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2306);
											mem_vec_2306 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2307);
											mem_vec_2307 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2308);
											mem_vec_2308 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2309);
											mem_vec_2309 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2310);
											mem_vec_2310 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2311);
											mem_vec_2311 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2312);
											mem_vec_2312 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2313);
											mem_vec_2313 = vec_28;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_2294);
											mem_vec_2294 = vec_29;
											vec_33 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_2295);
											mem_vec_2295 = vec_32;
											vec_35 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_2296);
											mem_vec_2296 = vec_34;
											vec_37 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_2297);
											mem_vec_2297 = vec_36;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_2298);
											mem_vec_2298 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_2299);
											mem_vec_2299 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_2300);
											mem_vec_2300 = vec_41;
											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_2301);
											mem_vec_2301 = vec_42;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_2302);
											mem_vec_2302 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_2303);
											mem_vec_2303 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_2304);
											mem_vec_2304 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_2305);
											mem_vec_2305 = vec_47;
											scal_8 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_2306);
											mem_vec_2306 = vec_48;
											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_2307);
											mem_vec_2307 = vec_50;
											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_2308);
											mem_vec_2308 = vec_51;
											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_2309);
											mem_vec_2309 = vec_52;
											scal_9 = input[strideA1 * (x + w + 1) + strideA2 * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);
											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_2310);
											mem_vec_2310 = vec_53;
											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_2311);
											mem_vec_2311 = vec_55;
											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_2312);
											mem_vec_2312 = vec_56;
											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_2313);
											mem_vec_2313 = vec_57;
											scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_2294);
											mem_vec_2294 = vec_58;
											vec_62 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_2295);
											mem_vec_2295 = vec_61;
											vec_64 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_2296);
											mem_vec_2296 = vec_63;
											vec_66 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_2297);
											mem_vec_2297 = vec_65;
											scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_2298);
											mem_vec_2298 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_2299);
											mem_vec_2299 = vec_69;
											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_2300);
											mem_vec_2300 = vec_70;
											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_2301);
											mem_vec_2301 = vec_71;
											scal_12 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);
											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_2302);
											mem_vec_2302 = vec_72;
											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_2303);
											mem_vec_2303 = vec_74;
											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_2304);
											mem_vec_2304 = vec_75;
											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_2305);
											mem_vec_2305 = vec_76;
											scal_13 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);
											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_2306);
											mem_vec_2306 = vec_77;
											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_2307);
											mem_vec_2307 = vec_79;
											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_2308);
											mem_vec_2308 = vec_80;
											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_2309);
											mem_vec_2309 = vec_81;
											scal_14 = input[strideA1 * (x + w + 2) + strideA2 * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);
											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_2310);
											mem_vec_2310 = vec_82;
											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_2311);
											mem_vec_2311 = vec_84;
											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_2312);
											mem_vec_2312 = vec_85;
											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_2313);
											mem_vec_2313 = vec_86;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_2294);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_2295);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_2296);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_2297);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_2298);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_2299);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_2300);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_2301);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_2302);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_2303);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_2304);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_2305);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_2306);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_2307);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_2308);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_2309);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_2310);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_2311);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_2312);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_2313);
							}
}
