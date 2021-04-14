#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (4, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (1, f);
  T (16, c); T (4, f)]
*/
IND_TYPE c, cp_0, c432_p_0, cp_1, c432, f, fp_0, f576_p_0, f577_p_0, fp_1, f576_p_1, fp_2, f576, f577, h, hp_0, w, wp_0, x, xp_0, x432_p_0, xp_1, x432, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y288 = 0;
IND_TYPE x433 = 0;
IND_TYPE h288 = 0;
IND_TYPE w288 = 0;
IND_TYPE c433 = 0;
IND_TYPE f578 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6240 ,mem_vec_6241 ,mem_vec_6242 ,mem_vec_6243 ,mem_vec_6244 ,mem_vec_6245 ,mem_vec_6246 ,mem_vec_6247 ,mem_vec_6248 ,mem_vec_6249 ,mem_vec_6250 ,mem_vec_6251 ,mem_vec_6252 ,mem_vec_6253 ,mem_vec_6254 ,mem_vec_6255 ,mem_vec_6256 ,mem_vec_6257 ,mem_vec_6258 ,mem_vec_6259 ,mem_vec_6260 ,mem_vec_6261 ,mem_vec_6262 ,mem_vec_6263 ,mem_vec_6264 ,mem_vec_6265 ,mem_vec_6266 ,mem_vec_6267 ,mem_vec_6268 ,mem_vec_6269 ,mem_vec_6270 ,mem_vec_6271 ,mem_vec_6272 ,mem_vec_6273 ,mem_vec_6274 ,mem_vec_6275 ,mem_vec_6276 ,mem_vec_6277 ,mem_vec_6278 ,mem_vec_6279 ,mem_vec_6280 ,mem_vec_6281 ,mem_vec_6282 ,mem_vec_6283 ,mem_vec_6284 ,mem_vec_6285 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f577 = f578, f577_p_0 = 0;
	f577 < f578 + 512;
	f577 += 128, f577_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (c, 16) (256 / 16)
	for (c432 = c433, c432_p_0 = 0;
		c432 < c433 + 256;
		c432 += 16, c432_p_0 += 16){
		// y = 34, x = 34, h = 3, w = 3, c = 16, f = 128
		// T (f, 1) (128 / 128)
		for (f576 = f577, f576_p_1 = f577_p_0, f576_p_0 = 0;
			f576 < f577 + 128;
			f576 += 128, f576_p_1 += 128, f576_p_0 += 128){
				for (y = y288, yp_0 = 0;
					y < y288 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 128
					// T (x, 2) (34 / 17)
					for (x432 = x433, x432_p_0 = 0;
						x432 < x433 + 34;
						x432 += 17, x432_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 128
						// T (f, 4) (128 / 32)
						for (f = f576, fp_2 = f576_p_1, fp_1 = f576_p_0, fp_0 = 0;
							f < f576 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h288, hp_0 = 0;
								h < h288 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w288, wp_0 = 0;
									w < w288 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
									// T (x, 17) (17 / 1)
									for (x = x432, xp_1 = x432_p_0, xp_0 = 0;
										x < x432 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c432, cp_1 = c432_p_0, cp_0 = 0;
													c < c432 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6240);
													mem_vec_6240 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6241);
													mem_vec_6241 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6242);
													mem_vec_6242 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6243);
													mem_vec_6243 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6244);
													mem_vec_6244 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6245);
													mem_vec_6245 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6246);
													mem_vec_6246 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6247);
													mem_vec_6247 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6248);
													mem_vec_6248 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6249);
													mem_vec_6249 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6250);
													mem_vec_6250 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6251);
													mem_vec_6251 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6252);
													mem_vec_6252 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6253);
													mem_vec_6253 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6254);
													mem_vec_6254 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6255);
													mem_vec_6255 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6256);
													mem_vec_6256 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6257);
													mem_vec_6257 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6258);
													mem_vec_6258 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6259);
													mem_vec_6259 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6260);
													mem_vec_6260 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6261);
													mem_vec_6261 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6240);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6241);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6242);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6243);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6244);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6245);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6246);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6247);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6248);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6249);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6250);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6251);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6252);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6253);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6254);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6255);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6256);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6257);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6258);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6259);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6261);
									}
								}
							}
						}
					}
				}
				for (y = y288 + 22, yp_0 = 0;
					y < y288 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 128
					// T (x, 2) (34 / 17)
					for (x432 = x433, x432_p_0 = 0;
						x432 < x433 + 34;
						x432 += 17, x432_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 128
						// T (f, 4) (128 / 32)
						for (f = f576, fp_2 = f576_p_1, fp_1 = f576_p_0, fp_0 = 0;
							f < f576 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h288, hp_0 = 0;
								h < h288 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w288, wp_0 = 0;
									w < w288 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 32
									// T (x, 17) (17 / 1)
									for (x = x432, xp_1 = x432_p_0, xp_0 = 0;
										x < x432 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6262 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6263 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c432, cp_1 = c432_p_0, cp_0 = 0;
													c < c432 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6262);
													mem_vec_6262 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6263);
													mem_vec_6263 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6264);
													mem_vec_6264 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6265);
													mem_vec_6265 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6266);
													mem_vec_6266 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6267);
													mem_vec_6267 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6268);
													mem_vec_6268 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6269);
													mem_vec_6269 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6270);
													mem_vec_6270 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6271);
													mem_vec_6271 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6272);
													mem_vec_6272 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6273);
													mem_vec_6273 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6274);
													mem_vec_6274 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6275);
													mem_vec_6275 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6276);
													mem_vec_6276 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6277);
													mem_vec_6277 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6278);
													mem_vec_6278 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6279);
													mem_vec_6279 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6280);
													mem_vec_6280 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6281);
													mem_vec_6281 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6282);
													mem_vec_6282 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6283);
													mem_vec_6283 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6284);
													mem_vec_6284 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6285);
													mem_vec_6285 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6265);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6266);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6267);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6268);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6269);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6270);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6271);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6272);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6273);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6274);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6275);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6276);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6277);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6278);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6279);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6280);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6281);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6282);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6283);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6284);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6285);
									}
								}
							}
						}
					}
				}
		}
	}
}


}