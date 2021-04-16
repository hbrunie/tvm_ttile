#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (2, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c594_p_0, cp_1, c594, f, fp_0, f792_p_0, f793_p_0, fp_1, f792_p_1, fp_2, f792, f793, h, hp_0, w, wp_0, x, xp_0, x594_p_0, xp_1, x594, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y396 = 0;
IND_TYPE x595 = 0;
IND_TYPE h284 = 0;
IND_TYPE w269 = 0;
IND_TYPE c595 = 0;
IND_TYPE f794 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8204 ,mem_vec_8205 ,mem_vec_8206 ,mem_vec_8207 ,mem_vec_8208 ,mem_vec_8209 ,mem_vec_8210 ,mem_vec_8211 ,mem_vec_8212 ,mem_vec_8213 ,mem_vec_8214 ,mem_vec_8215 ,mem_vec_8216 ,mem_vec_8217 ,mem_vec_8218 ,mem_vec_8219 ,mem_vec_8220 ,mem_vec_8221 ,mem_vec_8222 ,mem_vec_8223 ,mem_vec_8224 ,mem_vec_8225 ,mem_vec_8226 ,mem_vec_8227 ,mem_vec_8228 ,mem_vec_8229 ,mem_vec_8230 ,mem_vec_8231 ,mem_vec_8232 ,mem_vec_8233 ,mem_vec_8234 ,mem_vec_8235 ,mem_vec_8236 ,mem_vec_8237 ,mem_vec_8238 ,mem_vec_8239 ,mem_vec_8240 ,mem_vec_8241 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f793 = f794, f793_p_0 = 0;
	f793 < f794 + 256;
	f793 += 128, f793_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (f, 4) (128 / 32)
	for (f792 = f793, f792_p_1 = f793_p_0, f792_p_0 = 0;
		f792 < f793 + 128;
		f792 += 32, f792_p_1 += 32, f792_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 2) (68 / 34)
		for (x594 = x595, x594_p_0 = 0;
			x594 < x595 + 68;
			x594 += 34, x594_p_0 += 34){
				for (y = y396, yp_0 = 0;
					y < y396 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f792, fp_2 = f792_p_1, fp_1 = f792_p_0, fp_0 = 0;
						f < f792 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c594 = c595, c594_p_0 = 0;
							c594 < c595 + 128;
							c594 += 16, c594_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w269, wp_0 = 0;
								w < w269 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x594, xp_1 = x594_p_0, xp_0 = 0;
									x < x594 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h284, hp_0 = 0;
										h < h284 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8204 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8205 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c594, cp_1 = c594_p_0, cp_0 = 0;
													c < c594 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8204);
													mem_vec_8204 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8205);
													mem_vec_8205 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8206);
													mem_vec_8206 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8207);
													mem_vec_8207 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8208);
													mem_vec_8208 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8209);
													mem_vec_8209 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8210);
													mem_vec_8210 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8211);
													mem_vec_8211 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8212);
													mem_vec_8212 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8213);
													mem_vec_8213 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8214);
													mem_vec_8214 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8215);
													mem_vec_8215 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8216);
													mem_vec_8216 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8217);
													mem_vec_8217 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8218);
													mem_vec_8218 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8219);
													mem_vec_8219 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8220);
													mem_vec_8220 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8221);
													mem_vec_8221 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8204);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8205);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8206);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8207);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8208);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8209);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8210);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8211);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8212);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8213);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8214);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8215);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8216);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8217);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8218);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8219);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8220);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8221);
									}
								}
							}
						}
					}
				}
				for (y = y396 + 18, yp_0 = 0;
					y < y396 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f792, fp_2 = f792_p_1, fp_1 = f792_p_0, fp_0 = 0;
						f < f792 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c594 = c595, c594_p_0 = 0;
							c594 < c595 + 128;
							c594 += 16, c594_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w269, wp_0 = 0;
								w < w269 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
								// T (x, 34) (34 / 1)
								for (x = x594, xp_1 = x594_p_0, xp_0 = 0;
									x < x594 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h284, hp_0 = 0;
										h < h284 + 3;
										h += 1, hp_0 += 1){
												mem_vec_8222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_8238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_8240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_8241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c594, cp_1 = c594_p_0, cp_0 = 0;
													c < c594 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8222);
													mem_vec_8222 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8223);
													mem_vec_8223 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8224);
													mem_vec_8224 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8225);
													mem_vec_8225 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8226);
													mem_vec_8226 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8227);
													mem_vec_8227 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8228);
													mem_vec_8228 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8229);
													mem_vec_8229 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8230);
													mem_vec_8230 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8231);
													mem_vec_8231 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8232);
													mem_vec_8232 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8233);
													mem_vec_8233 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8234);
													mem_vec_8234 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8235);
													mem_vec_8235 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8236);
													mem_vec_8236 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8237);
													mem_vec_8237 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8238);
													mem_vec_8238 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8239);
													mem_vec_8239 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8240);
													mem_vec_8240 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8241);
													mem_vec_8241 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8222);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8223);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8224);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8225);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8226);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8227);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8228);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8229);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8230);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8231);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8232);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8233);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8234);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8235);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8236);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8237);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8238);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8239);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8240);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8241);
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