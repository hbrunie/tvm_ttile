#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (8, f);
  T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c578_p_0, cp_1, c578, f, fp_0, f584_p_0, f585_p_0, fp_1, f584_p_1, fp_2, f584, f585, h, hp_0, x, xp_0, x578_p_0, xp_1, x578, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y348 = 0;
IND_TYPE x579 = 0;
IND_TYPE h234 = 0;
IND_TYPE w = 0;
IND_TYPE c579 = 0;
IND_TYPE f586 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,mem_vec_5348 ,mem_vec_5349 ,mem_vec_5350 ,mem_vec_5351 ,mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f585 = f586, f585_p_0 = 0;
	f585 < f586 + 512;
	f585 += 256, f585_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 1) (256 / 256)
	for (c578 = c579, c578_p_0 = 0;
		c578 < c579 + 256;
		c578 += 256, c578_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f584 = f585, f584_p_1 = f585_p_0, f584_p_0 = 0;
			f584 < f585 + 256;
			f584 += 32, f584_p_1 += 32, f584_p_0 += 32){
				for (y = y348, yp_0 = 0;
					y < y348 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 34) (34 / 1)
					for (x578 = x579, x578_p_0 = 0;
						x578 < x579 + 34;
						x578 += 1, x578_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f584, fp_2 = f584_p_1, fp_1 = f584_p_0, fp_0 = 0;
							f < f584 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (h, 3) (3 / 1)
							for (h = h234, hp_0 = 0;
								h < h234 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
								// T (x, 1) (1 / 1)
								for (x = x578, xp_1 = x578_p_0, xp_0 = 0;
									x < x578 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5344 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5345 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c578, cp_1 = c578_p_0, cp_0 = 0;
												c < c578 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5344);
												mem_vec_5344 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5345);
												mem_vec_5345 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5346);
												mem_vec_5346 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5347);
												mem_vec_5347 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5348);
												mem_vec_5348 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5349);
												mem_vec_5349 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5350);
												mem_vec_5350 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5351);
												mem_vec_5351 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_5344);
												mem_vec_5344 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_5345);
												mem_vec_5345 = vec_17;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_20 = _mm512_set1_ps(scal_5);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_5346);
												mem_vec_5346 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_5347);
												mem_vec_5347 = vec_21;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_23 = _mm512_set1_ps(scal_6);


												vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_5348);
												mem_vec_5348 = vec_22;



												vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_5349);
												mem_vec_5349 = vec_24;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_26 = _mm512_set1_ps(scal_7);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_5350);
												mem_vec_5350 = vec_25;



												vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_5351);
												mem_vec_5351 = vec_27;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_5344);
												mem_vec_5344 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_5345);
												mem_vec_5345 = vec_31;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_9);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5346);
												mem_vec_5346 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5347);
												mem_vec_5347 = vec_35;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_37 = _mm512_set1_ps(scal_10);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_5348);
												mem_vec_5348 = vec_36;



												vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_5349);
												mem_vec_5349 = vec_38;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_40 = _mm512_set1_ps(scal_11);


												vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_5350);
												mem_vec_5350 = vec_39;



												vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_5351);
												mem_vec_5351 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5344);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5345);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5346);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5347);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5348);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5349);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5350);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5351);
								}
							}
						}
					}
				}
				for (y = y348 + 4, yp_0 = 0;
					y < y348 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (x, 34) (34 / 1)
					for (x578 = x579, x578_p_0 = 0;
						x578 < x579 + 34;
						x578 += 1, x578_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f584, fp_2 = f584_p_1, fp_1 = f584_p_0, fp_0 = 0;
							f < f584 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (h, 3) (3 / 1)
							for (h = h234, hp_0 = 0;
								h < h234 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
								// T (x, 1) (1 / 1)
								for (x = x578, xp_1 = x578_p_0, xp_0 = 0;
									x < x578 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5352 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5353 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c578, cp_1 = c578_p_0, cp_0 = 0;
												c < c578 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5352);
												mem_vec_5352 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5353);
												mem_vec_5353 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5354);
												mem_vec_5354 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5355);
												mem_vec_5355 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5356);
												mem_vec_5356 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5357);
												mem_vec_5357 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5358);
												mem_vec_5358 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5359);
												mem_vec_5359 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5360);
												mem_vec_5360 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5361);
												mem_vec_5361 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5362);
												mem_vec_5362 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5363);
												mem_vec_5363 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);
												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_5352);
												mem_vec_5352 = vec_20;

												vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_5353);
												mem_vec_5353 = vec_23;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_26 = _mm512_set1_ps(scal_7);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_5354);
												mem_vec_5354 = vec_25;



												vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_5355);
												mem_vec_5355 = vec_27;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_5356);
												mem_vec_5356 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_5357);
												mem_vec_5357 = vec_30;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_5358);
												mem_vec_5358 = vec_31;



												vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_5359);
												mem_vec_5359 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_5360);
												mem_vec_5360 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_5361);
												mem_vec_5361 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_5362);
												mem_vec_5362 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_5363);
												mem_vec_5363 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);
												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_5352);
												mem_vec_5352 = vec_40;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_5353);
												mem_vec_5353 = vec_43;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_46 = _mm512_set1_ps(scal_13);


												vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_5354);
												mem_vec_5354 = vec_45;



												vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_5355);
												mem_vec_5355 = vec_47;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_14);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5356);
												mem_vec_5356 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_5357);
												mem_vec_5357 = vec_50;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_52 = _mm512_set1_ps(scal_15);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_5358);
												mem_vec_5358 = vec_51;



												vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_5359);
												mem_vec_5359 = vec_53;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_55 = _mm512_set1_ps(scal_16);


												vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_5360);
												mem_vec_5360 = vec_54;



												vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_5361);
												mem_vec_5361 = vec_56;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_58 = _mm512_set1_ps(scal_17);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_5362);
												mem_vec_5362 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_5363);
												mem_vec_5363 = vec_59;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5352);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5353);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5354);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5355);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5356);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5357);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5358);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5359);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5360);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5361);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5362);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5363);
								}
							}
						}
					}
				}
		}
	}
}


}