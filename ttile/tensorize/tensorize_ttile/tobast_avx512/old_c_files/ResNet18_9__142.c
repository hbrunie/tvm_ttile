#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (2, x);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))];
  T (1, f); T (1, c); T (8, f); T (1, c); T (7, x); T (1, f)]
*/
IND_TYPE c, cp_0, c798_p_0, c799_p_0, cp_1, c798_p_1, cp_2, c798, c799, f, fp_0, f790_p_0, f791_p_0, fp_1, f790_p_1, fp_2, f790, f791, h, hp_0, x, xp_0, x664_p_0, xp_1, x664, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y444 = 0;
IND_TYPE x665 = 0;
IND_TYPE h370 = 0;
IND_TYPE w = 0;
IND_TYPE c800 = 0;
IND_TYPE f792 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4260 ,mem_vec_4261 ,mem_vec_4262 ,mem_vec_4263 ,mem_vec_4264 ,mem_vec_4265 ,mem_vec_4266 ,mem_vec_4267 ,mem_vec_4268 ,mem_vec_4269 ,mem_vec_4270 ,mem_vec_4271 ,mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f791 = f792, f791_p_0 = 0;
	f791 < f792 + 256;
	f791 += 256, f791_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (x, 7) (14 / 2)
	for (x664 = x665, x664_p_0 = 0;
		x664 < x665 + 14;
		x664 += 2, x664_p_0 += 2){
		// y = 14, x = 2, h = 3, w = 3, c = 256, f = 256
		// T (c, 1) (256 / 256)
		for (c799 = c800, c799_p_0 = 0;
			c799 < c800 + 256;
			c799 += 256, c799_p_0 += 256){
			// y = 14, x = 2, h = 3, w = 3, c = 256, f = 256
			// T (f, 8) (256 / 32)
			for (f790 = f791, f790_p_1 = f791_p_0, f790_p_0 = 0;
				f790 < f791 + 256;
				f790 += 32, f790_p_1 += 32, f790_p_0 += 32){
				// y = 14, x = 2, h = 3, w = 3, c = 256, f = 32
				// T (c, 1) (256 / 256)
				for (c798 = c799, c798_p_1 = c799_p_0, c798_p_0 = 0;
					c798 < c799 + 256;
					c798 += 256, c798_p_1 += 256, c798_p_0 += 256){
					// y = 14, x = 2, h = 3, w = 3, c = 256, f = 32
					// T (f, 1) (32 / 32)
					for (f = f790, fp_2 = f790_p_1, fp_1 = f790_p_0, fp_0 = 0;
						f < f790 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y444, yp_0 = 0;
								y < y444 + 8;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 32
								// T (h, 3) (3 / 1)
								for (h = h370, hp_0 = 0;
									h < h370 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 256, f = 32
									// T (x, 2) (2 / 1)
									for (x = x664, xp_1 = x664_p_0, xp_0 = 0;
										x < x664 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4260 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4261 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c798, cp_2 = c798_p_1, cp_1 = c798_p_0, cp_0 = 0;
													c < c798 + 256;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4260);
													mem_vec_4260 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4261);
													mem_vec_4261 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4262);
													mem_vec_4262 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4263);
													mem_vec_4263 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4264);
													mem_vec_4264 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4265);
													mem_vec_4265 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4266);
													mem_vec_4266 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4267);
													mem_vec_4267 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4260);
													mem_vec_4260 = vec_14;

													vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4261);
													mem_vec_4261 = vec_17;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_4262);
													mem_vec_4262 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_4263);
													mem_vec_4263 = vec_21;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_4264);
													mem_vec_4264 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_4265);
													mem_vec_4265 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_4266);
													mem_vec_4266 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_4267);
													mem_vec_4267 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4260);
													mem_vec_4260 = vec_28;

													vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4261);
													mem_vec_4261 = vec_31;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);


													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_4262);
													mem_vec_4262 = vec_33;



													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_4263);
													mem_vec_4263 = vec_35;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);


													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_4264);
													mem_vec_4264 = vec_36;



													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_4265);
													mem_vec_4265 = vec_38;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_4266);
													mem_vec_4266 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_4267);
													mem_vec_4267 = vec_41;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4260);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4261);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4262);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4263);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4264);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4265);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4266);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4267);
									}
								}
							}
							for (y = y444 + 8, yp_0 = 0;
								y < y444 + 8 + 6;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 32
								// T (h, 3) (3 / 1)
								for (h = h370, hp_0 = 0;
									h < h370 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 256, f = 32
									// T (x, 2) (2 / 1)
									for (x = x664, xp_1 = x664_p_0, xp_0 = 0;
										x < x664 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4268 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4269 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c798, cp_2 = c798_p_1, cp_1 = c798_p_0, cp_0 = 0;
													c < c798 + 256;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4268);
													mem_vec_4268 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4269);
													mem_vec_4269 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4270);
													mem_vec_4270 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4271);
													mem_vec_4271 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4272);
													mem_vec_4272 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4273);
													mem_vec_4273 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4274);
													mem_vec_4274 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4275);
													mem_vec_4275 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4276);
													mem_vec_4276 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4277);
													mem_vec_4277 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4278);
													mem_vec_4278 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4279);
													mem_vec_4279 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_4268);
													mem_vec_4268 = vec_20;

													vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_4269);
													mem_vec_4269 = vec_23;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_4270);
													mem_vec_4270 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_4271);
													mem_vec_4271 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_4272);
													mem_vec_4272 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_4273);
													mem_vec_4273 = vec_30;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_4274);
													mem_vec_4274 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_4275);
													mem_vec_4275 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_4276);
													mem_vec_4276 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_4277);
													mem_vec_4277 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_4278);
													mem_vec_4278 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_4279);
													mem_vec_4279 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_4268);
													mem_vec_4268 = vec_40;

													vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_4269);
													mem_vec_4269 = vec_43;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_4270);
													mem_vec_4270 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_4271);
													mem_vec_4271 = vec_47;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_4272);
													mem_vec_4272 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_4273);
													mem_vec_4273 = vec_50;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_52 = _mm512_set1_ps(scal_15);


													vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_4274);
													mem_vec_4274 = vec_51;



													vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_4275);
													mem_vec_4275 = vec_53;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_55 = _mm512_set1_ps(scal_16);


													vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_4276);
													mem_vec_4276 = vec_54;



													vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_4277);
													mem_vec_4277 = vec_56;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_4278);
													mem_vec_4278 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_4279);
													mem_vec_4279 = vec_59;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4268);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4269);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4270);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4271);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4272);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4273);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4274);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4275);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4276);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4277);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4278);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4279);
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