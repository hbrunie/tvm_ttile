void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))];
  T (1, f); T (32, c); T (4, f); T (68, x); T (2, f)]
*/
IND_TYPE c, cp_0, c996_p_0, cp_1, c996, f, fp_0, f1328_p_0, f1329_p_0, fp_1, f1328_p_1, fp_2, f1328, f1329, h, hp_0, w, wp_0, x, xp_0, x1048_p_0, xp_1, x1048, y, yp_0;
IND_TYPE y664 = 0;
IND_TYPE x1049 = 0;
IND_TYPE h664 = 0;
IND_TYPE w612 = 0;
IND_TYPE c997 = 0;
IND_TYPE f1330 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13220 ,mem_vec_13221 ,mem_vec_13222 ,mem_vec_13223 ,mem_vec_13224 ,mem_vec_13225 ,mem_vec_13226 ,mem_vec_13227 ,mem_vec_13228 ,mem_vec_13229 ,mem_vec_13230 ,mem_vec_13231 ,mem_vec_13232 ,mem_vec_13233 ,mem_vec_13234 ,mem_vec_13235 ,mem_vec_13236 ,mem_vec_13237 ,mem_vec_13238 ,mem_vec_13239 ,mem_vec_13240 ,mem_vec_13241 ,mem_vec_13242 ,mem_vec_13243 ,mem_vec_13244 ,mem_vec_13245 ,mem_vec_13246 ,mem_vec_13247 ,mem_vec_13248 ,mem_vec_13249 ,mem_vec_13250 ,mem_vec_13251 ,mem_vec_13252 ,mem_vec_13253 ,mem_vec_13254 ,mem_vec_13255 ,mem_vec_13256 ,mem_vec_13257 ,mem_vec_13258 ,mem_vec_13259 ,mem_vec_13260 ,mem_vec_13261 ,mem_vec_13262 ,mem_vec_13263 ,mem_vec_13264 ,mem_vec_13265 ,mem_vec_13266 ,mem_vec_13267 ,mem_vec_13268 ,mem_vec_13269 ,mem_vec_13270 ,mem_vec_13271 ,mem_vec_13272 ,mem_vec_13273 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
f1329 = 0;
f1329_p_0 = 0;
x1048 = 0;
x1048_p_0 = 0;
f1328 = 0;
f1328_p_1 = 0;
c996 = 0;
c996_p_0 = 0;
f = 0;
fp_2 = 0;
y = 0;
yp_0 = 0;
							for (h = h664, hp_0 = 0;h < h664 + 3;h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w612, wp_0 = 0;w < w612 + 3;w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1048, xp_1 = x1048_p_0, xp_0 = 0;x < x1048 + 1;x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13246 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_13247 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_13248 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_13249 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_13250 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_13251 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_13252 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_13253 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_13254 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_13255 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_13256 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
												mem_vec_13257 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
												mem_vec_13258 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
												mem_vec_13259 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
												mem_vec_13260 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f]);
												mem_vec_13261 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16]);
												mem_vec_13262 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f]);
												mem_vec_13263 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16]);
												mem_vec_13264 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f]);
												mem_vec_13265 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16]);
												mem_vec_13266 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f]);
												mem_vec_13267 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16]);
												mem_vec_13268 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f]);
												mem_vec_13269 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16]);
												mem_vec_13270 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f]);
												mem_vec_13271 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16]);
												mem_vec_13272 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f]);
												mem_vec_13273 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c996, cp_1 = c996_p_0, cp_0 = 0;c < c996 + 4;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13246);
													mem_vec_13246 = vec_0;
													vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13247);
													mem_vec_13247 = vec_3;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);
													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13248);
													mem_vec_13248 = vec_5;
													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13249);
													mem_vec_13249 = vec_7;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);
													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13250);
													mem_vec_13250 = vec_8;
													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13251);
													mem_vec_13251 = vec_10;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);
													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13252);
													mem_vec_13252 = vec_11;
													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13253);
													mem_vec_13253 = vec_13;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13254);
													mem_vec_13254 = vec_14;
													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13255);
													mem_vec_13255 = vec_16;
													scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13256);
													mem_vec_13256 = vec_17;
													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13257);
													mem_vec_13257 = vec_19;
													scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13258);
													mem_vec_13258 = vec_20;
													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13259);
													mem_vec_13259 = vec_22;
													scal_7 = input[strideA1 * (x + w) + strideA2 * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);
													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13260);
													mem_vec_13260 = vec_23;
													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13261);
													mem_vec_13261 = vec_25;
													scal_8 = input[strideA1 * (x + w) + strideA2 * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13262);
													mem_vec_13262 = vec_26;
													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13263);
													mem_vec_13263 = vec_28;
													scal_9 = input[strideA1 * (x + w) + strideA2 * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13264);
													mem_vec_13264 = vec_29;
													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13265);
													mem_vec_13265 = vec_31;
													scal_10 = input[strideA1 * (x + w) + strideA2 * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);
													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13266);
													mem_vec_13266 = vec_32;
													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13267);
													mem_vec_13267 = vec_34;
													scal_11 = input[strideA1 * (x + w) + strideA2 * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);
													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13268);
													mem_vec_13268 = vec_35;
													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13269);
													mem_vec_13269 = vec_37;
													scal_12 = input[strideA1 * (x + w) + strideA2 * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);
													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13270);
													mem_vec_13270 = vec_38;
													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13271);
													mem_vec_13271 = vec_40;
													scal_13 = input[strideA1 * (x + w) + strideA2 * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);
													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_13272);
													mem_vec_13272 = vec_41;
													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_13273);
													mem_vec_13273 = vec_43;
												}
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13246);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13247);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13248);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13249);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13250);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13251);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13252);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13253);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_13254);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_13255);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_13256);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_13257);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_13258);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_13259);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f], mem_vec_13260);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 7) + f + 16], mem_vec_13261);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f], mem_vec_13262);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 8) + f + 16], mem_vec_13263);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f], mem_vec_13264);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 9) + f + 16], mem_vec_13265);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f], mem_vec_13266);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 10) + f + 16], mem_vec_13267);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f], mem_vec_13268);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 11) + f + 16], mem_vec_13269);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f], mem_vec_13270);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 12) + f + 16], mem_vec_13271);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f], mem_vec_13272);
											_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 13) + f + 16], mem_vec_13273);
									}
								}
							}
}
