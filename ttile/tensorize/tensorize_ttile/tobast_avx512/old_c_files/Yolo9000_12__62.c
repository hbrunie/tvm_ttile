#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (8, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (2, f);
  T (64, c); T (1, f)]
*/
IND_TYPE c, cp_0, c584_p_0, cp_1, c584, f, fp_0, f592_p_0, f593_p_0, fp_1, f592_p_1, fp_2, f592, f593, h, hp_0, x, xp_0, x584_p_0, xp_1, x584, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y352 = 0;
IND_TYPE x585 = 0;
IND_TYPE h238 = 0;
IND_TYPE w = 0;
IND_TYPE c585 = 0;
IND_TYPE f594 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5384 ,mem_vec_5385 ,mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,mem_vec_5400 ,mem_vec_5401 ,mem_vec_5402 ,mem_vec_5403 ,mem_vec_5404 ,mem_vec_5405 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f593 = f594, f593_p_0 = 0;
	f593 < f594 + 512;
	f593 += 512, f593_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 64) (256 / 4)
	for (c584 = c585, c584_p_0 = 0;
		c584 < c585 + 256;
		c584 += 4, c584_p_0 += 4){
		// y = 34, x = 34, h = 3, w = 3, c = 4, f = 512
		// T (f, 2) (512 / 256)
		for (f592 = f593, f592_p_1 = f593_p_0, f592_p_0 = 0;
			f592 < f593 + 512;
			f592 += 256, f592_p_1 += 256, f592_p_0 += 256){
				for (y = y352, yp_0 = 0;
					y < y352 + 20;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
					// T (x, 1) (34 / 34)
					for (x584 = x585, x584_p_0 = 0;
						x584 < x585 + 34;
						x584 += 34, x584_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
						// T (f, 8) (256 / 32)
						for (f = f592, fp_2 = f592_p_1, fp_1 = f592_p_0, fp_0 = 0;
							f < f592 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h238, hp_0 = 0;
								h < h238 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 4, f = 32
								// T (x, 34) (34 / 1)
								for (x = x584, xp_1 = x584_p_0, xp_0 = 0;
									x < x584 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c584, cp_1 = c584_p_0, cp_0 = 0;
												c < c584 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5384);
												mem_vec_5384 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5385);
												mem_vec_5385 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5386);
												mem_vec_5386 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5387);
												mem_vec_5387 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5388);
												mem_vec_5388 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5389);
												mem_vec_5389 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5390);
												mem_vec_5390 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5391);
												mem_vec_5391 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_5384);
												mem_vec_5384 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_5385);
												mem_vec_5385 = vec_17;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_20 = _mm512_set1_ps(scal_5);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_5386);
												mem_vec_5386 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_5387);
												mem_vec_5387 = vec_21;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_23 = _mm512_set1_ps(scal_6);


												vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_5388);
												mem_vec_5388 = vec_22;



												vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_5389);
												mem_vec_5389 = vec_24;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_26 = _mm512_set1_ps(scal_7);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_5390);
												mem_vec_5390 = vec_25;



												vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_5391);
												mem_vec_5391 = vec_27;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_5384);
												mem_vec_5384 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_5385);
												mem_vec_5385 = vec_31;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_9);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5386);
												mem_vec_5386 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5387);
												mem_vec_5387 = vec_35;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_37 = _mm512_set1_ps(scal_10);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_5388);
												mem_vec_5388 = vec_36;



												vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_5389);
												mem_vec_5389 = vec_38;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_40 = _mm512_set1_ps(scal_11);


												vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_5390);
												mem_vec_5390 = vec_39;



												vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_5391);
												mem_vec_5391 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5387);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5391);
								}
							}
						}
					}
				}
				for (y = y352 + 20, yp_0 = 0;
					y < y352 + 20 + 14;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
					// T (x, 1) (34 / 34)
					for (x584 = x585, x584_p_0 = 0;
						x584 < x585 + 34;
						x584 += 34, x584_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 256
						// T (f, 8) (256 / 32)
						for (f = f592, fp_2 = f592_p_1, fp_1 = f592_p_0, fp_0 = 0;
							f < f592 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h238, hp_0 = 0;
								h < h238 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 4, f = 32
								// T (x, 34) (34 / 1)
								for (x = x584, xp_1 = x584_p_0, xp_0 = 0;
									x < x584 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5392 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5393 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c584, cp_1 = c584_p_0, cp_0 = 0;
												c < c584 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5392);
												mem_vec_5392 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5393);
												mem_vec_5393 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5394);
												mem_vec_5394 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5395);
												mem_vec_5395 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5396);
												mem_vec_5396 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5397);
												mem_vec_5397 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5398);
												mem_vec_5398 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5399);
												mem_vec_5399 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5400);
												mem_vec_5400 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5401);
												mem_vec_5401 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5402);
												mem_vec_5402 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5403);
												mem_vec_5403 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5404);
												mem_vec_5404 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5405);
												mem_vec_5405 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_5392);
												mem_vec_5392 = vec_23;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_5393);
												mem_vec_5393 = vec_26;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_5394);
												mem_vec_5394 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_5395);
												mem_vec_5395 = vec_30;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_5396);
												mem_vec_5396 = vec_31;



												vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_5397);
												mem_vec_5397 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_5398);
												mem_vec_5398 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_5399);
												mem_vec_5399 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_5400);
												mem_vec_5400 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_5401);
												mem_vec_5401 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_5402);
												mem_vec_5402 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_5403);
												mem_vec_5403 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_5404);
												mem_vec_5404 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_5405);
												mem_vec_5405 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_47 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_5392);
												mem_vec_5392 = vec_46;

												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_5393);
												mem_vec_5393 = vec_49;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_52 = _mm512_set1_ps(scal_15);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_5394);
												mem_vec_5394 = vec_51;



												vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_5395);
												mem_vec_5395 = vec_53;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_55 = _mm512_set1_ps(scal_16);


												vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_5396);
												mem_vec_5396 = vec_54;



												vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_5397);
												mem_vec_5397 = vec_56;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_58 = _mm512_set1_ps(scal_17);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_5398);
												mem_vec_5398 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5399);
												mem_vec_5399 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_61 = _mm512_set1_ps(scal_18);


												vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_5400);
												mem_vec_5400 = vec_60;



												vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_5401);
												mem_vec_5401 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_5402);
												mem_vec_5402 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_5403);
												mem_vec_5403 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_5404);
												mem_vec_5404 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_5405);
												mem_vec_5405 = vec_68;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5392);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5393);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5394);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5395);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5396);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5397);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5398);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5399);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5400);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5401);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5402);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5403);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5404);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5405);
								}
							}
						}
					}
				}
		}
	}
}


}