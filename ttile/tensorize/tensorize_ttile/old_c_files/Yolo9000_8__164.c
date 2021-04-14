#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))];
  T (4, f); T (32, c); T (1, f); T (34, x); T (2, f)]
*/
IND_TYPE c, cp_0, c768_p_0, cp_1, c768, f, fp_0, f1024_p_0, f1025_p_0, fp_1, f1024_p_1, fp_2, f1024, f1025, h, hp_0, w, wp_0, x, xp_0, x820_p_0, xp_1, x820, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y512 = 0;
IND_TYPE x821 = 0;
IND_TYPE h512 = 0;
IND_TYPE w460 = 0;
IND_TYPE c769 = 0;
IND_TYPE f1026 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9384 ,mem_vec_9385 ,mem_vec_9386 ,mem_vec_9387 ,mem_vec_9388 ,mem_vec_9389 ,mem_vec_9390 ,mem_vec_9391 ,mem_vec_9392 ,mem_vec_9393 ,mem_vec_9394 ,mem_vec_9395 ,mem_vec_9396 ,mem_vec_9397 ,mem_vec_9398 ,mem_vec_9399 ,mem_vec_9400 ,mem_vec_9401 ,mem_vec_9402 ,mem_vec_9403 ,mem_vec_9404 ,mem_vec_9405 ,mem_vec_9406 ,mem_vec_9407 ,mem_vec_9408 ,mem_vec_9409 ,mem_vec_9410 ,mem_vec_9411 ,mem_vec_9412 ,mem_vec_9413 ,mem_vec_9414 ,mem_vec_9415 ,mem_vec_9416 ,mem_vec_9417 ,mem_vec_9418 ,mem_vec_9419 ,mem_vec_9420 ,mem_vec_9421 ,mem_vec_9422 ,mem_vec_9423 ,mem_vec_9424 ,mem_vec_9425 ,mem_vec_9426 ,mem_vec_9427 ,mem_vec_9428 ,mem_vec_9429 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f1025 = f1026, f1025_p_0 = 0;
	f1025 < f1026 + 256;
	f1025 += 128, f1025_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 34) (68 / 2)
	for (x820 = x821, x820_p_0 = 0;
		x820 < x821 + 68;
		x820 += 2, x820_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 128
		// T (f, 1) (128 / 128)
		for (f1024 = f1025, f1024_p_1 = f1025_p_0, f1024_p_0 = 0;
			f1024 < f1025 + 128;
			f1024 += 128, f1024_p_1 += 128, f1024_p_0 += 128){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 128
			// T (c, 32) (128 / 4)
			for (c768 = c769, c768_p_0 = 0;
				c768 < c769 + 128;
				c768 += 4, c768_p_0 += 4){
				// y = 68, x = 2, h = 3, w = 3, c = 4, f = 128
				// T (f, 4) (128 / 32)
				for (f = f1024, fp_2 = f1024_p_1, fp_1 = f1024_p_0, fp_0 = 0;
					f < f1024 + 128;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y512, yp_0 = 0;
							y < y512 + 54;
							y += 9, yp_0 += 9){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h512, hp_0 = 0;
								h < h512 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w460, wp_0 = 0;
									w < w460 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x820, xp_1 = x820_p_0, xp_0 = 0;
										x < x820 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
													c < c768 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9384);
													mem_vec_9384 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9385);
													mem_vec_9385 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9386);
													mem_vec_9386 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9387);
													mem_vec_9387 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9388);
													mem_vec_9388 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9389);
													mem_vec_9389 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9390);
													mem_vec_9390 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9391);
													mem_vec_9391 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9392);
													mem_vec_9392 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9393);
													mem_vec_9393 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9394);
													mem_vec_9394 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9395);
													mem_vec_9395 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9396);
													mem_vec_9396 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9397);
													mem_vec_9397 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9398);
													mem_vec_9398 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9399);
													mem_vec_9399 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9400);
													mem_vec_9400 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9401);
													mem_vec_9401 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9384);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9385);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9386);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9387);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9388);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9389);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9390);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9391);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9392);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9393);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9394);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9395);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9396);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9397);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9398);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9399);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9400);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9401);
									}
								}
							}
						}
						for (y = y512 + 54, yp_0 = 0;
							y < y512 + 54 + 14;
							y += 14, yp_0 += 14){
							// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h512, hp_0 = 0;
								h < h512 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w460, wp_0 = 0;
									w < w460 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
									// T (x, 2) (2 / 1)
									for (x = x820, xp_1 = x820_p_0, xp_0 = 0;
										x < x820 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9402 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9403 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_9424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_9425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_9426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_9427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_9428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_9429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c768, cp_1 = c768_p_0, cp_0 = 0;
													c < c768 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9402);
													mem_vec_9402 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9403);
													mem_vec_9403 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9404);
													mem_vec_9404 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9405);
													mem_vec_9405 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9406);
													mem_vec_9406 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9407);
													mem_vec_9407 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9408);
													mem_vec_9408 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9409);
													mem_vec_9409 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9410);
													mem_vec_9410 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9411);
													mem_vec_9411 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9412);
													mem_vec_9412 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9413);
													mem_vec_9413 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9414);
													mem_vec_9414 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9415);
													mem_vec_9415 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9416);
													mem_vec_9416 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9417);
													mem_vec_9417 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9418);
													mem_vec_9418 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9419);
													mem_vec_9419 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9420);
													mem_vec_9420 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9421);
													mem_vec_9421 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9422);
													mem_vec_9422 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9423);
													mem_vec_9423 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9424);
													mem_vec_9424 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9425);
													mem_vec_9425 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9426);
													mem_vec_9426 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9427);
													mem_vec_9427 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_9428);
													mem_vec_9428 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_9429);
													mem_vec_9429 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9402);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9403);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9404);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9405);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9406);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9407);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9408);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9409);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9410);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9411);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9412);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9413);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9414);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9415);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9416);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9417);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9418);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9419);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9420);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9421);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9422);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9423);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9424);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9425);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9426);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9427);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_9428);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_9429);
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