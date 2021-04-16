
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (1, c);
  T (2, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (1, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c6_p_0, cp_1, c6, f, fp_0, x, xp_0, x8_p_0, x9_p_0, xp_1, x8_p_1, xp_2, x8, x9, y, yp_0, y6_p_0, yp_1, y6;
IND_TYPE y7 = 0;
IND_TYPE x10 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c7 = 0;
IND_TYPE f4 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_104 ,mem_vec_105 ,mem_vec_106 ,mem_vec_107 ,mem_vec_108 ,mem_vec_109 ,mem_vec_110 ,mem_vec_111 ,mem_vec_112 ,mem_vec_113 ,mem_vec_114 ,mem_vec_115 ,mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
y6 = 0;
y6_p_0 = 0;
	for (x9 = x10, x9_p_0 = 0;x9 < x10 + 68;x9 += 68, x9_p_0 += 68){
			for (y = y6, yp_1 = y6_p_0, yp_0 = 0;y < y6 + 6;y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (68 / 34)
				for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;x8 < x9 + 68;x8 += 34, x8_p_1 += 34, x8_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f4, fp_0 = 0;f < f4 + 128;f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c6 = c7, c6_p_0 = 0;c6 < c7 + 256;c6 += 256, c6_p_0 += 256){
							// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;x < x8 + 34;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_104 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_105 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_106 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_107 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_108 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_109 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_110 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_111 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_112 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_113 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_114 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_115 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_116 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_117 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_118 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_119 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_120 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_121 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_122 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_123 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_124 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_125 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_126 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_127 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c6, cp_1 = c6_p_0, cp_0 = 0;c < c6 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_104);
											mem_vec_104 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_105);
											mem_vec_105 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_106);
											mem_vec_106 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_107);
											mem_vec_107 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_108);
											mem_vec_108 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_109);
											mem_vec_109 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_110);
											mem_vec_110 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_111);
											mem_vec_111 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_112);
											mem_vec_112 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_113);
											mem_vec_113 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_114);
											mem_vec_114 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_115);
											mem_vec_115 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_116);
											mem_vec_116 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_117);
											mem_vec_117 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_118);
											mem_vec_118 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_119);
											mem_vec_119 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_120);
											mem_vec_120 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_121);
											mem_vec_121 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_122);
											mem_vec_122 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_123);
											mem_vec_123 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_124);
											mem_vec_124 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_125);
											mem_vec_125 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_126);
											mem_vec_126 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_127);
											mem_vec_127 = vec_33;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_104);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_105);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_106);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_107);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_108);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_109);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_110);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_111);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_112);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_113);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_114);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_115);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_116);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_117);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_118);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_119);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_120);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_121);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_122);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_123);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_124);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_125);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_126);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_127);
							}
						}
					}
				}
			}
			for (y = y6 + 6, yp_1 = y6_p_0, yp_0 = 0;y < y6 + 6 + 28;y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (68 / 34)
				for (x8 = x9, x8_p_1 = x9_p_0, x8_p_0 = 0;x8 < x9 + 68;x8 += 34, x8_p_1 += 34, x8_p_0 += 34){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f4, fp_0 = 0;f < f4 + 128;f += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c6 = c7, c6_p_0 = 0;c6 < c7 + 256;c6 += 256, c6_p_0 += 256){
							// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x8, xp_2 = x8_p_1, xp_1 = x8_p_0, xp_0 = 0;x < x8 + 34;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_128 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_129 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_130 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
										mem_vec_131 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
										mem_vec_132 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_133 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_134 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
										mem_vec_135 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
										mem_vec_136 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_137 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_138 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
										mem_vec_139 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
										mem_vec_140 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_141 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_142 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
										mem_vec_143 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
										mem_vec_144 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_145 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_146 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
										mem_vec_147 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
										mem_vec_148 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_149 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_150 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
										mem_vec_151 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
										mem_vec_152 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_153 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_154 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
										mem_vec_155 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c6, cp_1 = c6_p_0, cp_0 = 0;c < c6 + 256;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_128);
											mem_vec_128 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_129);
											mem_vec_129 = vec_3;
											vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_130);
											mem_vec_130 = vec_5;
											vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_131);
											mem_vec_131 = vec_7;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);
											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_132);
											mem_vec_132 = vec_9;
											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_133);
											mem_vec_133 = vec_11;
											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_134);
											mem_vec_134 = vec_12;
											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_135);
											mem_vec_135 = vec_13;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_136);
											mem_vec_136 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_137);
											mem_vec_137 = vec_16;
											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_138);
											mem_vec_138 = vec_17;
											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_139);
											mem_vec_139 = vec_18;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_140);
											mem_vec_140 = vec_19;
											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_141);
											mem_vec_141 = vec_21;
											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_142);
											mem_vec_142 = vec_22;
											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_143);
											mem_vec_143 = vec_23;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_144);
											mem_vec_144 = vec_24;
											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_145);
											mem_vec_145 = vec_26;
											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_146);
											mem_vec_146 = vec_27;
											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_147);
											mem_vec_147 = vec_28;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_148);
											mem_vec_148 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_149);
											mem_vec_149 = vec_31;
											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_150);
											mem_vec_150 = vec_32;
											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_151);
											mem_vec_151 = vec_33;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_152);
											mem_vec_152 = vec_34;
											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_153);
											mem_vec_153 = vec_36;
											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_154);
											mem_vec_154 = vec_37;
											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_155);
											mem_vec_155 = vec_38;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_128);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_129);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_130);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_131);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_132);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_133);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_134);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_135);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_136);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_137);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_138);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_139);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_140);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_141);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_142);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_143);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_144);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_145);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_146);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_147);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_148);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_149);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_150);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_151);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_152);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_153);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_154);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_155);
							}
						}
					}
				}
			}
	}
}
