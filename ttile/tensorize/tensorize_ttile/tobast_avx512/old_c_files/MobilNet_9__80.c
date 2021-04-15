#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (64, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (1, c);
  T (2, f); T (8, c)]
*/
IND_TYPE c, cp_0, c1628_p_0, c1629_p_0, c1630_p_0, cp_1, c1628_p_1, c1629_p_1, cp_2, c1628_p_2, cp_3, c1628, c1629, c1630, f, fp_0, f1092_p_0, fp_1, f1092, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y534 = 0;
IND_TYPE x680 = 0;
IND_TYPE h498 = 0;
IND_TYPE w = 0;
IND_TYPE c1631 = 0;
IND_TYPE f1093 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_6380 ,mem_vec_6381 ,mem_vec_6382 ,mem_vec_6383 ,mem_vec_6384 ,mem_vec_6385 ,mem_vec_6386 ,mem_vec_6387 ,mem_vec_6388 ,mem_vec_6389 ,mem_vec_6390 ,mem_vec_6391 ,mem_vec_6392 ,mem_vec_6393 ,mem_vec_6394 ,mem_vec_6395 ,mem_vec_6396 ,mem_vec_6397 ,mem_vec_6398 ,mem_vec_6399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c1630 = c1631, c1630_p_0 = 0;
	c1630 < c1631 + 1024;
	c1630 += 128, c1630_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (f, 2) (1024 / 512)
	for (f1092 = f1093, f1092_p_0 = 0;
		f1092 < f1093 + 1024;
		f1092 += 512, f1092_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 512
		// T (c, 1) (128 / 128)
		for (c1629 = c1630, c1629_p_1 = c1630_p_0, c1629_p_0 = 0;
			c1629 < c1630 + 128;
			c1629 += 128, c1629_p_1 += 128, c1629_p_0 += 128){
				for (y = y534, yp_0 = 0;
					y < y534 + 4;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1092, fp_1 = f1092_p_0, fp_0 = 0;
						f < f1092 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 64
						// T (c, 64) (128 / 2)
						for (c1628 = c1629, c1628_p_2 = c1629_p_1, c1628_p_1 = c1629_p_0, c1628_p_0 = 0;
							c1628 < c1629 + 128;
							c1628 += 2, c1628_p_2 += 2, c1628_p_1 += 2, c1628_p_0 += 2){
							// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h498, hp_0 = 0;
								h < h498 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
								// T (x, 7) (7 / 1)
								for (x = x680, xp_0 = 0;
									x < x680 + 7;
									x += 1, xp_0 += 1){
											mem_vec_6380 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6381 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6382 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6383 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
											// T (c, 2) (2 / 1)
											for (c = c1628, cp_3 = c1628_p_2, cp_2 = c1628_p_1, cp_1 = c1628_p_0, cp_0 = 0;
												c < c1628 + 2;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6380);
												mem_vec_6380 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6381);
												mem_vec_6381 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6382);
												mem_vec_6382 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6383);
												mem_vec_6383 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6384);
												mem_vec_6384 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6385);
												mem_vec_6385 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6386);
												mem_vec_6386 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6387);
												mem_vec_6387 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_6380);
												mem_vec_6380 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_6381);
												mem_vec_6381 = vec_17;

												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_6382);
												mem_vec_6382 = vec_19;

												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_6383);
												mem_vec_6383 = vec_21;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_24 = _mm512_set1_ps(scal_3);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_6384);
												mem_vec_6384 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_6385);
												mem_vec_6385 = vec_25;



												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_6386);
												mem_vec_6386 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_6387);
												mem_vec_6387 = vec_27;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_6380);
												mem_vec_6380 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_6381);
												mem_vec_6381 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_6382);
												mem_vec_6382 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_6383);
												mem_vec_6383 = vec_35;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_38 = _mm512_set1_ps(scal_5);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_6384);
												mem_vec_6384 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_6385);
												mem_vec_6385 = vec_39;



												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_6386);
												mem_vec_6386 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_6387);
												mem_vec_6387 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6380);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6381);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6383);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6384);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6385);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6386);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6387);
								}
							}
						}
					}
				}
				for (y = y534 + 4, yp_0 = 0;
					y < y534 + 4 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1092, fp_1 = f1092_p_0, fp_0 = 0;
						f < f1092 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 64
						// T (c, 64) (128 / 2)
						for (c1628 = c1629, c1628_p_2 = c1629_p_1, c1628_p_1 = c1629_p_0, c1628_p_0 = 0;
							c1628 < c1629 + 128;
							c1628 += 2, c1628_p_2 += 2, c1628_p_1 += 2, c1628_p_0 += 2){
							// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
							// T (h, 3) (3 / 1)
							for (h = h498, hp_0 = 0;
								h < h498 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 64
								// T (x, 7) (7 / 1)
								for (x = x680, xp_0 = 0;
									x < x680 + 7;
									x += 1, xp_0 += 1){
											mem_vec_6388 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6389 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6390 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_6391 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_6392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_6395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_6396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_6399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
											// T (c, 2) (2 / 1)
											for (c = c1628, cp_3 = c1628_p_2, cp_2 = c1628_p_1, cp_1 = c1628_p_0, cp_0 = 0;
												c < c1628 + 2;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6388);
												mem_vec_6388 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6389);
												mem_vec_6389 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6390);
												mem_vec_6390 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6391);
												mem_vec_6391 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6392);
												mem_vec_6392 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6393);
												mem_vec_6393 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6394);
												mem_vec_6394 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6395);
												mem_vec_6395 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6396);
												mem_vec_6396 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6397);
												mem_vec_6397 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6398);
												mem_vec_6398 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6399);
												mem_vec_6399 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_6388);
												mem_vec_6388 = vec_19;

												vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_6389);
												mem_vec_6389 = vec_22;

												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_6390);
												mem_vec_6390 = vec_24;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_6391);
												mem_vec_6391 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6392);
												mem_vec_6392 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_6393);
												mem_vec_6393 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6394);
												mem_vec_6394 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6395);
												mem_vec_6395 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_6396);
												mem_vec_6396 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_6397);
												mem_vec_6397 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_6398);
												mem_vec_6398 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_6399);
												mem_vec_6399 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_6388);
												mem_vec_6388 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_6389);
												mem_vec_6389 = vec_41;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_6390);
												mem_vec_6390 = vec_43;

												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_6391);
												mem_vec_6391 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_48 = _mm512_set1_ps(scal_7);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_6392);
												mem_vec_6392 = vec_47;



												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_6393);
												mem_vec_6393 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_6394);
												mem_vec_6394 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_6395);
												mem_vec_6395 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_53 = _mm512_set1_ps(scal_8);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_6396);
												mem_vec_6396 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_6397);
												mem_vec_6397 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_6398);
												mem_vec_6398 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_6399);
												mem_vec_6399 = vec_56;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6388);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6389);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6390);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6391);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6392);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6393);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6394);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6395);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6396);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6397);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6398);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6399);
								}
							}
						}
					}
				}
		}
	}
}


}