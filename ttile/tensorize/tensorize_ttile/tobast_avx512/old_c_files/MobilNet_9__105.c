#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (1, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 2)); ((Iter 1), (Arg 5))]; T (16, c);
  T (4, f); T (64, c)]
*/
IND_TYPE c, cp_0, c1428_p_0, c1429_p_0, c1430_p_0, cp_1, c1428_p_1, c1429_p_1, cp_2, c1428_p_2, cp_3, c1428, c1429, c1430, f, fp_0, f972_p_0, fp_1, f972, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y454 = 0;
IND_TYPE x600 = 0;
IND_TYPE h = 0;
IND_TYPE w480 = 0;
IND_TYPE c1431 = 0;
IND_TYPE f973 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5356 ,mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,mem_vec_5364 ,mem_vec_5365 ,mem_vec_5366 ,mem_vec_5367 ,mem_vec_5368 ,mem_vec_5369 ,mem_vec_5370 ,mem_vec_5371 ,mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 64) (1024 / 16)
for (c1430 = c1431, c1430_p_0 = 0;
	c1430 < c1431 + 1024;
	c1430 += 16, c1430_p_0 += 16){
	// y = 7, x = 7, h = 3, w = 3, c = 16, f = 1024
	// T (f, 4) (1024 / 256)
	for (f972 = f973, f972_p_0 = 0;
		f972 < f973 + 1024;
		f972 += 256, f972_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 16, f = 256
		// T (c, 16) (16 / 1)
		for (c1429 = c1430, c1429_p_1 = c1430_p_0, c1429_p_0 = 0;
			c1429 < c1430 + 16;
			c1429 += 1, c1429_p_1 += 1, c1429_p_0 += 1){
				for (y = y454, yp_0 = 0;
					y < y454 + 2;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 256
					// T (f, 4) (256 / 64)
					for (f = f972, fp_1 = f972_p_0, fp_0 = 0;
						f < f972 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
						// T (c, 1) (1 / 1)
						for (c1428 = c1429, c1428_p_2 = c1429_p_1, c1428_p_1 = c1429_p_0, c1428_p_0 = 0;
							c1428 < c1429 + 1;
							c1428 += 1, c1428_p_2 += 1, c1428_p_1 += 1, c1428_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (w, 3) (3 / 1)
							for (w = w480, wp_0 = 0;
								w < w480 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x600, xp_0 = 0;
									x < x600 + 7;
									x += 1, xp_0 += 1){
											mem_vec_5356 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5357 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5358 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5359 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1428, cp_3 = c1428_p_2, cp_2 = c1428_p_1, cp_1 = c1428_p_0, cp_0 = 0;
												c < c1428 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5356);
												mem_vec_5356 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5357);
												mem_vec_5357 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5358);
												mem_vec_5358 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5359);
												mem_vec_5359 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5360);
												mem_vec_5360 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5361);
												mem_vec_5361 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5362);
												mem_vec_5362 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5363);
												mem_vec_5363 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_5356);
												mem_vec_5356 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_5357);
												mem_vec_5357 = vec_17;

												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_5358);
												mem_vec_5358 = vec_19;

												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_5359);
												mem_vec_5359 = vec_21;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_24 = _mm512_set1_ps(scal_3);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_5360);
												mem_vec_5360 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_5361);
												mem_vec_5361 = vec_25;



												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_5362);
												mem_vec_5362 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_5363);
												mem_vec_5363 = vec_27;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_5356);
												mem_vec_5356 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_5357);
												mem_vec_5357 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_5358);
												mem_vec_5358 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_5359);
												mem_vec_5359 = vec_35;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_5);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_5360);
												mem_vec_5360 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_5361);
												mem_vec_5361 = vec_39;



												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_5362);
												mem_vec_5362 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_5363);
												mem_vec_5363 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5356);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5357);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5358);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5359);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5360);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5361);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5362);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5363);
								}
							}
						}
					}
				}
				for (y = y454 + 2, yp_0 = 0;
					y < y454 + 2 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 256
					// T (f, 4) (256 / 64)
					for (f = f972, fp_1 = f972_p_0, fp_0 = 0;
						f < f972 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
						// T (c, 1) (1 / 1)
						for (c1428 = c1429, c1428_p_2 = c1429_p_1, c1428_p_1 = c1429_p_0, c1428_p_0 = 0;
							c1428 < c1429 + 1;
							c1428 += 1, c1428_p_2 += 1, c1428_p_1 += 1, c1428_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (w, 3) (3 / 1)
							for (w = w480, wp_0 = 0;
								w < w480 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x600, xp_0 = 0;
									x < x600 + 7;
									x += 1, xp_0 += 1){
											mem_vec_5364 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5365 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5366 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5367 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_5376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_5379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_5380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_5383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1428, cp_3 = c1428_p_2, cp_2 = c1428_p_1, cp_1 = c1428_p_0, cp_0 = 0;
												c < c1428 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5364);
												mem_vec_5364 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5365);
												mem_vec_5365 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5366);
												mem_vec_5366 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5367);
												mem_vec_5367 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5368);
												mem_vec_5368 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5369);
												mem_vec_5369 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5370);
												mem_vec_5370 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5371);
												mem_vec_5371 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5372);
												mem_vec_5372 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5373);
												mem_vec_5373 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5374);
												mem_vec_5374 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5375);
												mem_vec_5375 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5376);
												mem_vec_5376 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5377);
												mem_vec_5377 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5378);
												mem_vec_5378 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5379);
												mem_vec_5379 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5380);
												mem_vec_5380 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5381);
												mem_vec_5381 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5382);
												mem_vec_5382 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5383);
												mem_vec_5383 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_5364);
												mem_vec_5364 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_5365);
												mem_vec_5365 = vec_32;

												vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_5366);
												mem_vec_5366 = vec_34;

												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_5367);
												mem_vec_5367 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_5368);
												mem_vec_5368 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_5369);
												mem_vec_5369 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_5370);
												mem_vec_5370 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_5371);
												mem_vec_5371 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_5372);
												mem_vec_5372 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_5373);
												mem_vec_5373 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_5374);
												mem_vec_5374 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5375);
												mem_vec_5375 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_5376);
												mem_vec_5376 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_5377);
												mem_vec_5377 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_5378);
												mem_vec_5378 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_5379);
												mem_vec_5379 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_5380);
												mem_vec_5380 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_5381);
												mem_vec_5381 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_5382);
												mem_vec_5382 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_5383);
												mem_vec_5383 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_5364);
												mem_vec_5364 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_5365);
												mem_vec_5365 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_5366);
												mem_vec_5366 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_5367);
												mem_vec_5367 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_5368);
												mem_vec_5368 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_5369);
												mem_vec_5369 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_5370);
												mem_vec_5370 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_5371);
												mem_vec_5371 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_12);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_5372);
												mem_vec_5372 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_5373);
												mem_vec_5373 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_5374);
												mem_vec_5374 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5375);
												mem_vec_5375 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_5376);
												mem_vec_5376 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_5377);
												mem_vec_5377 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_5378);
												mem_vec_5378 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_5379);
												mem_vec_5379 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_5380);
												mem_vec_5380 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_5381);
												mem_vec_5381 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_5382);
												mem_vec_5382 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_5383);
												mem_vec_5383 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5364);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5365);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5366);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5367);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5368);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5369);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5370);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5371);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5372);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5373);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5374);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5375);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5376);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5377);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5378);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5379);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5380);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5381);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5382);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5383);
								}
							}
						}
					}
				}
		}
	}
}


}