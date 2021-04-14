void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (112, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (8, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c672_p_0, cp_1, c672, h, hp_0, w, wp_0, x, xp_0, x896_p_0, x897_p_0, xp_1, x896_p_1, xp_2, x896, x897, y, yp_0;
IND_TYPE y448 = 0;
IND_TYPE x898 = 0;
IND_TYPE h428 = 0;
IND_TYPE w448 = 0;
IND_TYPE c673 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8212 ,mem_vec_8213 ,mem_vec_8214 ,mem_vec_8215 ,mem_vec_8216 ,mem_vec_8217 ,mem_vec_8218 ,mem_vec_8219 ,mem_vec_8220 ,mem_vec_8221 ,mem_vec_8222 ,mem_vec_8223 ,mem_vec_8224 ,mem_vec_8225 ,mem_vec_8226 ,mem_vec_8227 ,mem_vec_8228 ,mem_vec_8229 ,mem_vec_8230 ,mem_vec_8231 ,mem_vec_8232 ,mem_vec_8233 ,mem_vec_8234 ,mem_vec_8235 ,mem_vec_8236 ,mem_vec_8237 ,mem_vec_8238 ,mem_vec_8239 ,mem_vec_8240 ,mem_vec_8241 ,mem_vec_8242 ,mem_vec_8243 ,mem_vec_8244 ,mem_vec_8245 ,mem_vec_8246 ,mem_vec_8247 ,mem_vec_8248 ,mem_vec_8249 ,mem_vec_8250 ,mem_vec_8251 ,mem_vec_8252 ,mem_vec_8253 ,mem_vec_8254 ,mem_vec_8255 ,mem_vec_8256 ,mem_vec_8257 ,mem_vec_8258 ,mem_vec_8259 ,mem_vec_8260 ,mem_vec_8261 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 1) (112 / 112)
x897 = 0;
x897_p_0 = 0;
c672 = 0;
c672_p_0 = 0;
y = 0;
yp_0 = 0;
x896 = 0;
x896_p_1 = 0;
					for (h = h428, hp_0 = 0;h < h428 + 3;h += 1, hp_0 += 1){
						// y = ph_y, x = 112, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w448, wp_0 = 0;w < w448 + 3;w += 1, wp_0 += 1){
							// y = ph_y, x = 112, h = 1, w = 1, c = 4, f = 32
							// T (x, 112) (112 / 1)
							for (x = x896, xp_2 = x896_p_1, xp_1 = x896_p_0, xp_0 = 0;x < x896 + 112;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8236 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
										mem_vec_8237 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
										mem_vec_8238 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
										mem_vec_8239 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
										mem_vec_8240 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
										mem_vec_8241 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
										mem_vec_8242 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
										mem_vec_8243 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
										mem_vec_8244 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
										mem_vec_8245 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
										mem_vec_8246 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
										mem_vec_8247 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
										mem_vec_8248 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
										mem_vec_8249 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
										mem_vec_8250 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
										mem_vec_8251 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
										mem_vec_8252 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
										mem_vec_8253 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
										mem_vec_8254 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
										mem_vec_8255 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
										mem_vec_8256 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
										mem_vec_8257 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
										mem_vec_8258 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
										mem_vec_8259 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
										mem_vec_8260 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
										mem_vec_8261 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c672, cp_1 = c672_p_0, cp_0 = 0;c < c672 + 4;c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8236);
											mem_vec_8236 = vec_0;
											vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8237);
											mem_vec_8237 = vec_3;
											scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);
											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8238);
											mem_vec_8238 = vec_5;
											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8239);
											mem_vec_8239 = vec_7;
											scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);
											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8240);
											mem_vec_8240 = vec_8;
											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8241);
											mem_vec_8241 = vec_10;
											scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);
											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8242);
											mem_vec_8242 = vec_11;
											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8243);
											mem_vec_8243 = vec_13;
											scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);
											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8244);
											mem_vec_8244 = vec_14;
											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8245);
											mem_vec_8245 = vec_16;
											scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8246);
											mem_vec_8246 = vec_17;
											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8247);
											mem_vec_8247 = vec_19;
											scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8248);
											mem_vec_8248 = vec_20;
											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8249);
											mem_vec_8249 = vec_22;
											scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8250);
											mem_vec_8250 = vec_23;
											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8251);
											mem_vec_8251 = vec_25;
											scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);
											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8252);
											mem_vec_8252 = vec_26;
											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8253);
											mem_vec_8253 = vec_28;
											scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8254);
											mem_vec_8254 = vec_29;
											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8255);
											mem_vec_8255 = vec_31;
											scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8256);
											mem_vec_8256 = vec_32;
											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8257);
											mem_vec_8257 = vec_34;
											scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8258);
											mem_vec_8258 = vec_35;
											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8259);
											mem_vec_8259 = vec_37;
											scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8260);
											mem_vec_8260 = vec_38;
											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8261);
											mem_vec_8261 = vec_40;
										}
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8236);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8237);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8238);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8239);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8240);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8241);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8242);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8243);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8244);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8245);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8246);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8247);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8248);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8249);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8250);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8251);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8252);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8253);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8254);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_8255);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_8256);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_8257);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_8258);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_8259);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_8260);
									_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_8261);
							}
						}
					}
}
