
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (2, f); T (16, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c1050_p_0, cp_1, c1050, f, fp_0, f1050_p_0, fp_1, f1050, h, hp_0, x, xp_0, x1050_p_0, xp_1, x1050, y, yp_0;
IND_TYPE y700 = 0;
IND_TYPE x1051 = 0;
IND_TYPE h562 = 0;
IND_TYPE w = 0;
IND_TYPE c1051 = 0;
IND_TYPE f1051 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8992 ,mem_vec_8993 ,mem_vec_8994 ,mem_vec_8995 ,mem_vec_8996 ,mem_vec_8997 ,mem_vec_8998 ,mem_vec_8999 ,mem_vec_9000 ,mem_vec_9001 ,mem_vec_9002 ,mem_vec_9003 ,mem_vec_9004 ,mem_vec_9005 ,mem_vec_9006 ,mem_vec_9007 ,mem_vec_9008 ,mem_vec_9009 ,mem_vec_9010 ,mem_vec_9011 ,mem_vec_9012 ,mem_vec_9013 ,mem_vec_9014 ,mem_vec_9015 ,mem_vec_9016 ,mem_vec_9017 ,mem_vec_9018 ,mem_vec_9019 ,mem_vec_9020 ,mem_vec_9021 ,mem_vec_9022 ,mem_vec_9023 ,mem_vec_9024 ,mem_vec_9025 ,mem_vec_9026 ,mem_vec_9027 ,mem_vec_9028 ,mem_vec_9029 ,mem_vec_9030 ,mem_vec_9031 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
f1050 = 0;
f1050_p_0 = 0;
y = 0;
yp_0 = 0;
x1050 = 0;
x1050_p_0 = 0;
c1050 = 0;
c1050_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h562, hp_0 = 0;h < h562 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 16, f = 64
							// T (x, 14) (14 / 1)
							for (x = x1050, xp_1 = x1050_p_0, xp_0 = 0;x < x1050 + 14;x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8992 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_8993 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_8994 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_8995 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_8996 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_8997 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_8998 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_8999 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_9000 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_9001 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_9002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_9003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_9004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_9005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_9006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_9007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c1050, cp_1 = c1050_p_0, cp_0 = 0;c < c1050 + 16;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8992);
											mem_vec_8992 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8993);
											mem_vec_8993 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8994);
											mem_vec_8994 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8995);
											mem_vec_8995 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8996);
											mem_vec_8996 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8997);
											mem_vec_8997 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8998);
											mem_vec_8998 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8999);
											mem_vec_8999 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9000);
											mem_vec_9000 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9001);
											mem_vec_9001 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9002);
											mem_vec_9002 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9003);
											mem_vec_9003 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9004);
											mem_vec_9004 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9005);
											mem_vec_9005 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9006);
											mem_vec_9006 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9007);
											mem_vec_9007 = vec_23;
											scal_4 = input[strideA1 * (x + w + 1) + strideA2 * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f]);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_8992);
											mem_vec_8992 = vec_24;
											vec_28 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 16]);
											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_8993);
											mem_vec_8993 = vec_27;
											vec_30 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 32]);
											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_8994);
											mem_vec_8994 = vec_29;
											vec_32 = _mm512_loadu_ps(&params[strideW1 * (w + 1) + strideW2 * h + strideW3 * c + f + 48]);
											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_8995);
											mem_vec_8995 = vec_31;
											scal_5 = input[strideA1 * (x + w + 1) + strideA2 * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);
											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_8996);
											mem_vec_8996 = vec_33;
											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_8997);
											mem_vec_8997 = vec_35;
											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_8998);
											mem_vec_8998 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_8999);
											mem_vec_8999 = vec_37;
											scal_6 = input[strideA1 * (x + w + 1) + strideA2 * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_9000);
											mem_vec_9000 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_9001);
											mem_vec_9001 = vec_40;
											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_9002);
											mem_vec_9002 = vec_41;
											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_9003);
											mem_vec_9003 = vec_42;
											scal_7 = input[strideA1 * (x + w + 1) + strideA2 * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);
											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_9004);
											mem_vec_9004 = vec_43;
											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_9005);
											mem_vec_9005 = vec_45;
											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_9006);
											mem_vec_9006 = vec_46;
											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_9007);
											mem_vec_9007 = vec_47;
											scal_8 = input[strideA1 * (x + w + 2) + strideA2 * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f]);
											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_8992);
											mem_vec_8992 = vec_48;
											vec_52 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 16]);
											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_8993);
											mem_vec_8993 = vec_51;
											vec_54 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 32]);
											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_8994);
											mem_vec_8994 = vec_53;
											vec_56 = _mm512_loadu_ps(&params[strideW1 * (w + 2) + strideW2 * h + strideW3 * c + f + 48]);
											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_8995);
											mem_vec_8995 = vec_55;
											scal_9 = input[strideA1 * (x + w + 2) + strideA2 * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);
											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_8996);
											mem_vec_8996 = vec_57;
											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_8997);
											mem_vec_8997 = vec_59;
											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_8998);
											mem_vec_8998 = vec_60;
											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_8999);
											mem_vec_8999 = vec_61;
											scal_10 = input[strideA1 * (x + w + 2) + strideA2 * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);
											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_9000);
											mem_vec_9000 = vec_62;
											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_9001);
											mem_vec_9001 = vec_64;
											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_9002);
											mem_vec_9002 = vec_65;
											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_9003);
											mem_vec_9003 = vec_66;
											scal_11 = input[strideA1 * (x + w + 2) + strideA2 * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);
											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_9004);
											mem_vec_9004 = vec_67;
											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_9005);
											mem_vec_9005 = vec_69;
											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_9006);
											mem_vec_9006 = vec_70;
											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_9007);
											mem_vec_9007 = vec_71;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8992);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8993);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_8994);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_8995);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8996);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8997);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_8998);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_8999);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_9000);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_9001);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_9002);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_9003);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_9004);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_9005);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_9006);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_9007);
							}
						}
}
