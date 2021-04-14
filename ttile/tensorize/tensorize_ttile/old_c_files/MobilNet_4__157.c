#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (2, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]; T (2, f)]
*/
IND_TYPE c, cp_0, c540_p_0, cp_1, c540, f, fp_0, f540_p_0, fp_1, f540, h, hp_0, w, wp_0, x, xp_0, x540_p_0, xp_1, x540, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y360 = 0;
IND_TYPE x541 = 0;
IND_TYPE h292 = 0;
IND_TYPE w330 = 0;
IND_TYPE c541 = 0;
IND_TYPE f541 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4600 ,mem_vec_4601 ,mem_vec_4602 ,mem_vec_4603 ,mem_vec_4604 ,mem_vec_4605 ,mem_vec_4606 ,mem_vec_4607 ,mem_vec_4608 ,mem_vec_4609 ,mem_vec_4610 ,mem_vec_4611 ,mem_vec_4612 ,mem_vec_4613 ,mem_vec_4614 ,mem_vec_4615 ,mem_vec_4616 ,mem_vec_4617 ,mem_vec_4618 ,mem_vec_4619 ,mem_vec_4620 ,mem_vec_4621 ,mem_vec_4622 ,mem_vec_4623 ,mem_vec_4624 ,mem_vec_4625 ,mem_vec_4626 ,mem_vec_4627 ,mem_vec_4628 ,mem_vec_4629 ,mem_vec_4630 ,mem_vec_4631 ,mem_vec_4632 ,mem_vec_4633 ,mem_vec_4634 ,mem_vec_4635 ,mem_vec_4636 ,mem_vec_4637 ,mem_vec_4638 ,mem_vec_4639 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f540 = f541, f540_p_0 = 0;
	f540 < f541 + 128;
	f540 += 64, f540_p_0 += 64){
		for (y = y360, yp_0 = 0;
			y < y360 + 16;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 2) (28 / 14)
			for (x540 = x541, x540_p_0 = 0;
				x540 < x541 + 28;
				x540 += 14, x540_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (c, 4) (128 / 32)
				for (c540 = c541, c540_p_0 = 0;
					c540 < c541 + 128;
					c540 += 32, c540_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
					// T (f, 2) (64 / 32)
					for (f = f540, fp_1 = f540_p_0, fp_0 = 0;
						f < f540 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h292, hp_0 = 0;
							h < h292 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w330, wp_0 = 0;
								w < w330 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x540, xp_1 = x540_p_0, xp_0 = 0;
									x < x540 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4600 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4601 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
												c < c540 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4600);
												mem_vec_4600 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4601);
												mem_vec_4601 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4602);
												mem_vec_4602 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4603);
												mem_vec_4603 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4604);
												mem_vec_4604 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4605);
												mem_vec_4605 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4606);
												mem_vec_4606 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4607);
												mem_vec_4607 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4608);
												mem_vec_4608 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4609);
												mem_vec_4609 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4610);
												mem_vec_4610 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4611);
												mem_vec_4611 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4612);
												mem_vec_4612 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4613);
												mem_vec_4613 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4614);
												mem_vec_4614 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4615);
												mem_vec_4615 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4600);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4601);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4602);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4603);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4604);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4605);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4606);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4607);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4608);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4609);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4610);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4611);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4612);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4613);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4614);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4615);
								}
							}
						}
					}
				}
			}
		}
		for (y = y360 + 16, yp_0 = 0;
			y < y360 + 16 + 12;
			y += 12, yp_0 += 12){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 2) (28 / 14)
			for (x540 = x541, x540_p_0 = 0;
				x540 < x541 + 28;
				x540 += 14, x540_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
				// T (c, 4) (128 / 32)
				for (c540 = c541, c540_p_0 = 0;
					c540 < c541 + 128;
					c540 += 32, c540_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
					// T (f, 2) (64 / 32)
					for (f = f540, fp_1 = f540_p_0, fp_0 = 0;
						f < f540 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h292, hp_0 = 0;
							h < h292 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w330, wp_0 = 0;
								w < w330 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x540, xp_1 = x540_p_0, xp_0 = 0;
									x < x540 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4616 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4617 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_4638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_4639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c540, cp_1 = c540_p_0, cp_0 = 0;
												c < c540 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4616);
												mem_vec_4616 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4617);
												mem_vec_4617 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4618);
												mem_vec_4618 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4619);
												mem_vec_4619 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4620);
												mem_vec_4620 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4621);
												mem_vec_4621 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4622);
												mem_vec_4622 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4623);
												mem_vec_4623 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4624);
												mem_vec_4624 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4625);
												mem_vec_4625 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4626);
												mem_vec_4626 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4627);
												mem_vec_4627 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4628);
												mem_vec_4628 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4629);
												mem_vec_4629 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4630);
												mem_vec_4630 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4631);
												mem_vec_4631 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4632);
												mem_vec_4632 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4633);
												mem_vec_4633 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4634);
												mem_vec_4634 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4635);
												mem_vec_4635 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4636);
												mem_vec_4636 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4637);
												mem_vec_4637 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4638);
												mem_vec_4638 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4639);
												mem_vec_4639 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4616);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4617);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4618);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4619);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4620);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4621);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4622);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4623);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4624);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4625);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4626);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4627);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4628);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4629);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4630);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4631);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4632);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4633);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4634);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4635);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4636);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4637);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4638);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4639);
								}
							}
						}
					}
				}
			}
		}
}


}