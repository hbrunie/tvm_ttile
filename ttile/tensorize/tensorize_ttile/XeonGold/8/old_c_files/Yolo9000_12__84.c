#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]; T (16, f);
  T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c417_p_0, cp_1, c417, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x421_p_0, x422_p_0, xp_1, x421_p_1, xp_2, x421, x422, y, yp_0, y300_p_0, yp_1, y300;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y301 = 0;
IND_TYPE x423 = 0;
IND_TYPE h260 = 0;
IND_TYPE w179 = 0;
IND_TYPE c418 = 0;
IND_TYPE f512 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6183 ,mem_vec_6184 ,mem_vec_6185 ,mem_vec_6186 ,mem_vec_6187 ,mem_vec_6188 ,mem_vec_6189 ,mem_vec_6190 ,mem_vec_6191 ,mem_vec_6192 ,mem_vec_6193 ,mem_vec_6194 ,mem_vec_6195 ,mem_vec_6196 ,mem_vec_6197 ,mem_vec_6198 ,mem_vec_6199 ,mem_vec_6200 ,mem_vec_6201 ,mem_vec_6202 ,mem_vec_6203 ,mem_vec_6204 ,mem_vec_6205 ,mem_vec_6206 ,mem_vec_6207 ,mem_vec_6208 ,mem_vec_6209 ,mem_vec_6210 ,mem_vec_6211 ,mem_vec_6212 ,mem_vec_6213 ,mem_vec_6214 ,mem_vec_6215 ,mem_vec_6216 ,mem_vec_6217 ,mem_vec_6218 ,mem_vec_6219 ,mem_vec_6220 ,mem_vec_6221 ,mem_vec_6222 ,mem_vec_6223 ,mem_vec_6224 ,mem_vec_6225 ,mem_vec_6226 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (y, 1) (34 / 34)
for (y300 = y301, y300_p_0 = 0;
	y300 < y301 + 34;
	y300 += 34, y300_p_0 += 34){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 2) (34 / 17)
	for (x422 = x423, x422_p_0 = 0;
		x422 < x423 + 34;
		x422 += 17, x422_p_0 += 17){
		// y = 34, x = 17, h = 3, w = 3, c = 256, f = 512
		// T (f, 16) (512 / 32)
		for (f = f512, fp_0 = 0;
			f < f512 + 512;
			f += 32, fp_0 += 32){
				for (y = y300, yp_1 = y300_p_0, yp_0 = 0;
					y < y300 + 10;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (17 / 17)
					for (x421 = x422, x421_p_1 = x422_p_0, x421_p_0 = 0;
						x421 < x422 + 17;
						x421 += 17, x421_p_1 += 17, x421_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c417 = c418, c417_p_0 = 0;
							c417 < c418 + 256;
							c417 += 32, c417_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w179, wp_0 = 0;
								w < w179 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x421, xp_2 = x421_p_1, xp_1 = x421_p_0, xp_0 = 0;
									x < x421 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h260, hp_0 = 0;
										h < h260 + 3;
										h += 1, hp_0 += 1){
												mem_vec_6183 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6184 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c417, cp_1 = c417_p_0, cp_0 = 0;
													c < c417 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6183);
													mem_vec_6183 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6184);
													mem_vec_6184 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6185);
													mem_vec_6185 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6186);
													mem_vec_6186 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6187);
													mem_vec_6187 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6188);
													mem_vec_6188 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6189);
													mem_vec_6189 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6190);
													mem_vec_6190 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6191);
													mem_vec_6191 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6192);
													mem_vec_6192 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6193);
													mem_vec_6193 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6194);
													mem_vec_6194 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6195);
													mem_vec_6195 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6196);
													mem_vec_6196 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6197);
													mem_vec_6197 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6198);
													mem_vec_6198 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6199);
													mem_vec_6199 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6200);
													mem_vec_6200 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6201);
													mem_vec_6201 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6202);
													mem_vec_6202 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6183);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6184);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6185);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6186);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6187);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6188);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6189);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6190);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6191);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6192);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6193);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6194);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6195);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6196);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6197);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6198);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6199);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6200);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6201);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6202);
									}
								}
							}
						}
					}
				}
				for (y = y300 + 10, yp_1 = y300_p_0, yp_0 = 0;
					y < y300 + 10 + 24;
					y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (x, 1) (17 / 17)
					for (x421 = x422, x421_p_1 = x422_p_0, x421_p_0 = 0;
						x421 < x422 + 17;
						x421 += 17, x421_p_1 += 17, x421_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c417 = c418, c417_p_0 = 0;
							c417 < c418 + 256;
							c417 += 32, c417_p_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w179, wp_0 = 0;
								w < w179 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
								// T (x, 17) (17 / 1)
								for (x = x421, xp_2 = x421_p_1, xp_1 = x421_p_0, xp_0 = 0;
									x < x421 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h260, hp_0 = 0;
										h < h260 + 3;
										h += 1, hp_0 += 1){
												mem_vec_6203 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6204 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c417, cp_1 = c417_p_0, cp_0 = 0;
													c < c417 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6203);
													mem_vec_6203 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6204);
													mem_vec_6204 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6205);
													mem_vec_6205 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6206);
													mem_vec_6206 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6207);
													mem_vec_6207 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6208);
													mem_vec_6208 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6209);
													mem_vec_6209 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6210);
													mem_vec_6210 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6211);
													mem_vec_6211 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6212);
													mem_vec_6212 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6213);
													mem_vec_6213 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6214);
													mem_vec_6214 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6215);
													mem_vec_6215 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6216);
													mem_vec_6216 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6217);
													mem_vec_6217 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6218);
													mem_vec_6218 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6219);
													mem_vec_6219 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6220);
													mem_vec_6220 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6221);
													mem_vec_6221 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6222);
													mem_vec_6222 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6223);
													mem_vec_6223 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6224);
													mem_vec_6224 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6225);
													mem_vec_6225 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6226);
													mem_vec_6226 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6203);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6204);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6205);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6206);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6207);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6214);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6215);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6217);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6218);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6219);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6220);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6221);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6223);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6224);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6225);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6226);
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