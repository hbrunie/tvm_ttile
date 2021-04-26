#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (4, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, x);
  T (1, f); T (1, f)]
*/
IND_TYPE c, cp_0, c408_p_0, cp_1, c408, f, fp_0, f538_p_0, f539_p_0, fp_1, f538_p_1, fp_2, f538, f539, h, hp_0, w, wp_0, x, xp_0, x408_p_0, xp_1, x408, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y275 = 0;
IND_TYPE x409 = 0;
IND_TYPE h269 = 0;
IND_TYPE w249 = 0;
IND_TYPE c409 = 0;
IND_TYPE f540 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5228 ,mem_vec_5229 ,mem_vec_5230 ,mem_vec_5231 ,mem_vec_5232 ,mem_vec_5233 ,mem_vec_5234 ,mem_vec_5235 ,mem_vec_5236 ,mem_vec_5237 ,mem_vec_5238 ,mem_vec_5239 ,mem_vec_5240 ,mem_vec_5241 ,mem_vec_5242 ,mem_vec_5243 ,mem_vec_5244 ,mem_vec_5245 ,mem_vec_5246 ,mem_vec_5247 ,mem_vec_5248 ,mem_vec_5249 ,mem_vec_5250 ,mem_vec_5251 ,mem_vec_5252 ,mem_vec_5253 ,mem_vec_5254 ,mem_vec_5255 ,mem_vec_5256 ,mem_vec_5257 ,mem_vec_5258 ,mem_vec_5259 ,mem_vec_5260 ,mem_vec_5261 ,mem_vec_5262 ,mem_vec_5263 ,mem_vec_5264 ,mem_vec_5265 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f539 = f540, f539_p_0 = 0;
	f539 < f540 + 256;
	f539 += 256, f539_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (f, 1) (256 / 256)
	for (f538 = f539, f538_p_1 = f539_p_0, f538_p_0 = 0;
		f538 < f539 + 256;
		f538 += 256, f538_p_1 += 256, f538_p_0 += 256){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
		// T (x, 4) (68 / 17)
		for (x408 = x409, x408_p_0 = 0;
			x408 < x409 + 68;
			x408 += 17, x408_p_0 += 17){
				for (y = y275, yp_0 = 0;
					y < y275 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f538, fp_2 = f538_p_1, fp_1 = f538_p_0, fp_0 = 0;
						f < f538 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c408 = c409, c408_p_0 = 0;
							c408 < c409 + 128;
							c408 += 32, c408_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w249, wp_0 = 0;
								w < w249 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x408, xp_1 = x408_p_0, xp_0 = 0;
									x < x408 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h269, hp_0 = 0;
										h < h269 + 3;
										h += 1, hp_0 += 1){
												mem_vec_5228 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5229 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c408, cp_1 = c408_p_0, cp_0 = 0;
													c < c408 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5228);
													mem_vec_5228 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5229);
													mem_vec_5229 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5230);
													mem_vec_5230 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5231);
													mem_vec_5231 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5232);
													mem_vec_5232 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5233);
													mem_vec_5233 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5234);
													mem_vec_5234 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5235);
													mem_vec_5235 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5236);
													mem_vec_5236 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5237);
													mem_vec_5237 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5238);
													mem_vec_5238 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5239);
													mem_vec_5239 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5240);
													mem_vec_5240 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5241);
													mem_vec_5241 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5242);
													mem_vec_5242 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5243);
													mem_vec_5243 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5244);
													mem_vec_5244 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5245);
													mem_vec_5245 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5228);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5229);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5230);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5231);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5232);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5233);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5234);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5235);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5236);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5237);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5238);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5239);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5240);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5241);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5242);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5243);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5244);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5245);
									}
								}
							}
						}
					}
				}
				for (y = y275 + 18, yp_0 = 0;
					y < y275 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 256
					// T (f, 8) (256 / 32)
					for (f = f538, fp_2 = f538_p_1, fp_1 = f538_p_0, fp_0 = 0;
						f < f538 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 4) (128 / 32)
						for (c408 = c409, c408_p_0 = 0;
							c408 < c409 + 128;
							c408 += 32, c408_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w249, wp_0 = 0;
								w < w249 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x408, xp_1 = x408_p_0, xp_0 = 0;
									x < x408 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h269, hp_0 = 0;
										h < h269 + 3;
										h += 1, hp_0 += 1){
												mem_vec_5246 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5247 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_5264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_5265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c408, cp_1 = c408_p_0, cp_0 = 0;
													c < c408 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5246);
													mem_vec_5246 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5247);
													mem_vec_5247 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5248);
													mem_vec_5248 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5249);
													mem_vec_5249 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5250);
													mem_vec_5250 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5251);
													mem_vec_5251 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5252);
													mem_vec_5252 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5253);
													mem_vec_5253 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5254);
													mem_vec_5254 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5255);
													mem_vec_5255 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5256);
													mem_vec_5256 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5257);
													mem_vec_5257 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5258);
													mem_vec_5258 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5259);
													mem_vec_5259 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5260);
													mem_vec_5260 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5261);
													mem_vec_5261 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5262);
													mem_vec_5262 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5263);
													mem_vec_5263 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5264);
													mem_vec_5264 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5265);
													mem_vec_5265 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5246);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5247);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5248);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5249);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5250);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5251);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5252);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5253);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5254);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5255);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5256);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5257);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5258);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5259);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5261);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5265);
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