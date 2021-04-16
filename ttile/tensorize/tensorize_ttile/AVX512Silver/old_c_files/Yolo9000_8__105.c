#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (2, f);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (2, x);
  T (2, f); T (2, f)]
*/
IND_TYPE c, cp_0, c591_p_0, cp_1, c591, f, fp_0, f788_p_0, f789_p_0, fp_1, f788_p_1, fp_2, f788, f789, h, hp_0, w, wp_0, x, xp_0, x591_p_0, xp_1, x591, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y394 = 0;
IND_TYPE x592 = 0;
IND_TYPE h282 = 0;
IND_TYPE w267 = 0;
IND_TYPE c592 = 0;
IND_TYPE f790 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8166 ,mem_vec_8167 ,mem_vec_8168 ,mem_vec_8169 ,mem_vec_8170 ,mem_vec_8171 ,mem_vec_8172 ,mem_vec_8173 ,mem_vec_8174 ,mem_vec_8175 ,mem_vec_8176 ,mem_vec_8177 ,mem_vec_8178 ,mem_vec_8179 ,mem_vec_8180 ,mem_vec_8181 ,mem_vec_8182 ,mem_vec_8183 ,mem_vec_8184 ,mem_vec_8185 ,mem_vec_8186 ,mem_vec_8187 ,mem_vec_8188 ,mem_vec_8189 ,mem_vec_8190 ,mem_vec_8191 ,mem_vec_8192 ,mem_vec_8193 ,mem_vec_8194 ,mem_vec_8195 ,mem_vec_8196 ,mem_vec_8197 ,mem_vec_8198 ,mem_vec_8199 ,mem_vec_8200 ,mem_vec_8201 ,mem_vec_8202 ,mem_vec_8203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f789 = f790, f789_p_0 = 0;
	f789 < f790 + 256;
	f789 += 128, f789_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 2) (128 / 64)
	for (f788 = f789, f788_p_1 = f789_p_0, f788_p_0 = 0;
		f788 < f789 + 128;
		f788 += 64, f788_p_1 += 64, f788_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 2) (68 / 34)
		for (x591 = x592, x591_p_0 = 0;
			x591 < x592 + 68;
			x591 += 34, x591_p_0 += 34){
				for (y = y394, yp_0 = 0;
					y < y394 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f788, fp_2 = f788_p_1, fp_1 = f788_p_0, fp_0 = 0;
						f < f788 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c591 = c592, c591_p_0 = 0;
							c591 < c592 + 128;
							c591 += 16, c591_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w267, wp_0 = 0;
								w < w267 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x591, xp_1 = x591_p_0, xp_0 = 0;
									x < x591 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h282, hp_0 = 0;
										h < h282 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8166 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8167 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
													c < c591 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8166);
													mem_vec_8166 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8167);
													mem_vec_8167 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8168);
													mem_vec_8168 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8169);
													mem_vec_8169 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8170);
													mem_vec_8170 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8171);
													mem_vec_8171 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8172);
													mem_vec_8172 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8173);
													mem_vec_8173 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8174);
													mem_vec_8174 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8175);
													mem_vec_8175 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8176);
													mem_vec_8176 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8177);
													mem_vec_8177 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8178);
													mem_vec_8178 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8179);
													mem_vec_8179 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8180);
													mem_vec_8180 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8181);
													mem_vec_8181 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8182);
													mem_vec_8182 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8183);
													mem_vec_8183 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8166);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8167);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8168);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8169);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8170);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8171);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8172);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8173);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8174);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8175);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8176);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8177);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8178);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8179);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8180);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8181);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8182);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8183);
									}
								}
							}
						}
					}
				}
				for (y = y394 + 18, yp_0 = 0;
					y < y394 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f788, fp_2 = f788_p_1, fp_1 = f788_p_0, fp_0 = 0;
						f < f788 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c591 = c592, c591_p_0 = 0;
							c591 < c592 + 128;
							c591 += 16, c591_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w267, wp_0 = 0;
								w < w267 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x591, xp_1 = x591_p_0, xp_0 = 0;
									x < x591 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h282, hp_0 = 0;
										h < h282 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8184 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8185 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_8202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_8203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c591, cp_1 = c591_p_0, cp_0 = 0;
													c < c591 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8184);
													mem_vec_8184 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8185);
													mem_vec_8185 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8186);
													mem_vec_8186 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8187);
													mem_vec_8187 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8188);
													mem_vec_8188 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8189);
													mem_vec_8189 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8190);
													mem_vec_8190 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8191);
													mem_vec_8191 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8192);
													mem_vec_8192 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8193);
													mem_vec_8193 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8194);
													mem_vec_8194 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8195);
													mem_vec_8195 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8196);
													mem_vec_8196 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8197);
													mem_vec_8197 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8198);
													mem_vec_8198 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8199);
													mem_vec_8199 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8200);
													mem_vec_8200 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8201);
													mem_vec_8201 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8202);
													mem_vec_8202 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8203);
													mem_vec_8203 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8184);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8185);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8186);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8187);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8188);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8189);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8190);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8191);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8192);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8193);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8194);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8195);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8196);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8197);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8198);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8199);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8200);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8201);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8202);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8203);
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