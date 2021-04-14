void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, f); T (2, c); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (4, f)]
*/
IND_TYPE c, cp_0, c792_p_0, cp_1, c792, f, fp_0, f792_p_0, fp_1, f792, h, hp_0, w, wp_0, x, xp_0, x792_p_0, xp_1, x792, y, yp_0;
IND_TYPE y528 = 0;
IND_TYPE x793 = 0;
IND_TYPE h460 = 0;
IND_TYPE w498 = 0;
IND_TYPE c793 = 0;
IND_TYPE f793 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8220 ,mem_vec_8221 ,mem_vec_8222 ,mem_vec_8223 ,mem_vec_8224 ,mem_vec_8225 ,mem_vec_8226 ,mem_vec_8227 ,mem_vec_8228 ,mem_vec_8229 ,mem_vec_8230 ,mem_vec_8231 ,mem_vec_8232 ,mem_vec_8233 ,mem_vec_8234 ,mem_vec_8235 ,mem_vec_8236 ,mem_vec_8237 ,mem_vec_8238 ,mem_vec_8239 ,mem_vec_8240 ,mem_vec_8241 ,mem_vec_8242 ,mem_vec_8243 ,mem_vec_8244 ,mem_vec_8245 ,mem_vec_8246 ,mem_vec_8247 ,mem_vec_8248 ,mem_vec_8249 ,mem_vec_8250 ,mem_vec_8251 ,mem_vec_8252 ,mem_vec_8253 ,mem_vec_8254 ,mem_vec_8255 ,mem_vec_8256 ,mem_vec_8257 ,mem_vec_8258 ,mem_vec_8259 ,mem_vec_8260 ,mem_vec_8261 ,mem_vec_8262 ,mem_vec_8263 ,mem_vec_8264 ,mem_vec_8265 ,mem_vec_8266 ,mem_vec_8267 ,mem_vec_8268 ,mem_vec_8269 ,mem_vec_8270 ,mem_vec_8271 ,mem_vec_8272 ,mem_vec_8273 ,mem_vec_8274 ,mem_vec_8275 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
f792 = 0;
f792_p_0 = 0;
y = 0;
yp_0 = 0;
x792 = 0;
x792_p_0 = 0;
c792 = 0;
c792_p_0 = 0;
f = 0;
fp_1 = 0;
						for (h = h460, hp_0 = 0;h < h460 + 3;h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w498, wp_0 = 0;w < w498 + 3;w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 64, f = 32
								// T (x, 7) (7 / 1)
								for (x = x792, xp_1 = x792_p_0, xp_0 = 0;x < x792 + 7;x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8246 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
											mem_vec_8247 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
											mem_vec_8248 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
											mem_vec_8249 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
											mem_vec_8250 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
											mem_vec_8251 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
											mem_vec_8252 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
											mem_vec_8253 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
											mem_vec_8254 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
											mem_vec_8255 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
											mem_vec_8256 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
											mem_vec_8257 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
											mem_vec_8258 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
											mem_vec_8259 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
											mem_vec_8260 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
											mem_vec_8261 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
											mem_vec_8262 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
											mem_vec_8263 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
											mem_vec_8264 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
											mem_vec_8265 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
											mem_vec_8266 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
											mem_vec_8267 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
											mem_vec_8268 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
											mem_vec_8269 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
											mem_vec_8270 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
											mem_vec_8271 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
											mem_vec_8272 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
											mem_vec_8273 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
											mem_vec_8274 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f]);
											mem_vec_8275 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c792, cp_1 = c792_p_0, cp_0 = 0;c < c792 + 64;c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[strideA1 * (2 * x + w) + strideA2 * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8246);
												mem_vec_8246 = vec_0;
												vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8247);
												mem_vec_8247 = vec_3;
												scal_1 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);
												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8248);
												mem_vec_8248 = vec_5;
												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8249);
												mem_vec_8249 = vec_7;
												scal_2 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);
												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8250);
												mem_vec_8250 = vec_8;
												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8251);
												mem_vec_8251 = vec_10;
												scal_3 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);
												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8252);
												mem_vec_8252 = vec_11;
												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8253);
												mem_vec_8253 = vec_13;
												scal_4 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8254);
												mem_vec_8254 = vec_14;
												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8255);
												mem_vec_8255 = vec_16;
												scal_5 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);
												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8256);
												mem_vec_8256 = vec_17;
												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8257);
												mem_vec_8257 = vec_19;
												scal_6 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8258);
												mem_vec_8258 = vec_20;
												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8259);
												mem_vec_8259 = vec_22;
												scal_7 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8260);
												mem_vec_8260 = vec_23;
												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8261);
												mem_vec_8261 = vec_25;
												scal_8 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);
												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8262);
												mem_vec_8262 = vec_26;
												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8263);
												mem_vec_8263 = vec_28;
												scal_9 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8264);
												mem_vec_8264 = vec_29;
												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8265);
												mem_vec_8265 = vec_31;
												scal_10 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8266);
												mem_vec_8266 = vec_32;
												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8267);
												mem_vec_8267 = vec_34;
												scal_11 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);
												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8268);
												mem_vec_8268 = vec_35;
												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8269);
												mem_vec_8269 = vec_37;
												scal_12 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);
												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8270);
												mem_vec_8270 = vec_38;
												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8271);
												mem_vec_8271 = vec_40;
												scal_13 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 13) + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);
												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8272);
												mem_vec_8272 = vec_41;
												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8273);
												mem_vec_8273 = vec_43;
												scal_14 = input[strideA1 * (2 * x + w) + strideA2 * (2 * (y + 14) + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);
												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_8274);
												mem_vec_8274 = vec_44;
												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_8275);
												mem_vec_8275 = vec_46;
											}
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_8246);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_8247);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_8248);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_8249);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_8250);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_8251);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_8252);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_8253);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_8254);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_8255);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_8256);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_8257);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_8258);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_8259);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_8260);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_8261);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_8262);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_8263);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_8264);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_8265);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_8266);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_8267);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_8268);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_8269);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_8270);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_8271);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_8272);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_8273);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f], mem_vec_8274);
										_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 14) + f + 16], mem_vec_8275);
								}
							}
						}
}
