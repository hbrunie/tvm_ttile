#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, f); T (4, c); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (2, f)]
*/
IND_TYPE c, cp_0, c648_p_0, cp_1, c648, f, fp_0, f720_p_0, fp_1, f720, h, hp_0, w, wp_0, x, xp_0, x648_p_0, xp_1, x648, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y432 = 0;
IND_TYPE x649 = 0;
IND_TYPE h358 = 0;
IND_TYPE w382 = 0;
IND_TYPE c649 = 0;
IND_TYPE f721 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5420 ,mem_vec_5421 ,mem_vec_5422 ,mem_vec_5423 ,mem_vec_5424 ,mem_vec_5425 ,mem_vec_5426 ,mem_vec_5427 ,mem_vec_5428 ,mem_vec_5429 ,mem_vec_5430 ,mem_vec_5431 ,mem_vec_5432 ,mem_vec_5433 ,mem_vec_5434 ,mem_vec_5435 ,mem_vec_5436 ,mem_vec_5437 ,mem_vec_5438 ,mem_vec_5439 ,mem_vec_5440 ,mem_vec_5441 ,mem_vec_5442 ,mem_vec_5443 ,mem_vec_5444 ,mem_vec_5445 ,mem_vec_5446 ,mem_vec_5447 ,mem_vec_5448 ,mem_vec_5449 ,mem_vec_5450 ,mem_vec_5451 ,mem_vec_5452 ,mem_vec_5453 ,mem_vec_5454 ,mem_vec_5455 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f720 = f721, f720_p_0 = 0;
	f720 < f721 + 256;
	f720 += 128, f720_p_0 += 128){
		for (y = y432, yp_0 = 0;
			y < y432 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 14) (28 / 2)
			for (x648 = x649, x648_p_0 = 0;
				x648 < x649 + 28;
				x648 += 2, x648_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 128
				// T (c, 4) (128 / 32)
				for (c648 = c649, c648_p_0 = 0;
					c648 < c649 + 128;
					c648 += 32, c648_p_0 += 32){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 128
					// T (f, 4) (128 / 32)
					for (f = f720, fp_1 = f720_p_0, fp_0 = 0;
						f < f720 + 128;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h358, hp_0 = 0;
							h < h358 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w382, wp_0 = 0;
								w < w382 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x648, xp_1 = x648_p_0, xp_0 = 0;
									x < x648 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5420 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5421 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c648, cp_1 = c648_p_0, cp_0 = 0;
												c < c648 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5420);
												mem_vec_5420 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5421);
												mem_vec_5421 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5422);
												mem_vec_5422 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5423);
												mem_vec_5423 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5424);
												mem_vec_5424 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5425);
												mem_vec_5425 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5426);
												mem_vec_5426 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5427);
												mem_vec_5427 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5428);
												mem_vec_5428 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5429);
												mem_vec_5429 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5430);
												mem_vec_5430 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5431);
												mem_vec_5431 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5432);
												mem_vec_5432 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5433);
												mem_vec_5433 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5434);
												mem_vec_5434 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5435);
												mem_vec_5435 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5420);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5421);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5422);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5423);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5424);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5425);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5426);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5427);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5428);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5429);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5430);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5431);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5432);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5433);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5434);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5435);
								}
							}
						}
					}
				}
			}
		}
		for (y = y432 + 8, yp_0 = 0;
			y < y432 + 8 + 20;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 14) (28 / 2)
			for (x648 = x649, x648_p_0 = 0;
				x648 < x649 + 28;
				x648 += 2, x648_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 128
				// T (c, 4) (128 / 32)
				for (c648 = c649, c648_p_0 = 0;
					c648 < c649 + 128;
					c648 += 32, c648_p_0 += 32){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 128
					// T (f, 4) (128 / 32)
					for (f = f720, fp_1 = f720_p_0, fp_0 = 0;
						f < f720 + 128;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h358, hp_0 = 0;
							h < h358 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w382, wp_0 = 0;
								w < w382 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x648, xp_1 = x648_p_0, xp_0 = 0;
									x < x648 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5436 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5437 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c648, cp_1 = c648_p_0, cp_0 = 0;
												c < c648 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5436);
												mem_vec_5436 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5437);
												mem_vec_5437 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5438);
												mem_vec_5438 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5439);
												mem_vec_5439 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5440);
												mem_vec_5440 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5441);
												mem_vec_5441 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5442);
												mem_vec_5442 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5443);
												mem_vec_5443 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5444);
												mem_vec_5444 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5445);
												mem_vec_5445 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5446);
												mem_vec_5446 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5447);
												mem_vec_5447 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5448);
												mem_vec_5448 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5449);
												mem_vec_5449 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5450);
												mem_vec_5450 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5451);
												mem_vec_5451 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5452);
												mem_vec_5452 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5453);
												mem_vec_5453 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5454);
												mem_vec_5454 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5455);
												mem_vec_5455 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5436);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5437);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5438);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5439);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5452);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5453);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5455);
								}
							}
						}
					}
				}
			}
		}
}


}