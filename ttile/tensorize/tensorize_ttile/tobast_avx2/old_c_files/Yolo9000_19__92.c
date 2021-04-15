#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (2, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, f64_p_0, f65_p_0, fp_1, f64_p_1, fp_2, f64, f65, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y32 = 0;
IND_TYPE x66 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c49 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_576 ,mem_vec_577 ,mem_vec_578 ,mem_vec_579 ,mem_vec_580 ,mem_vec_581 ,mem_vec_582 ,mem_vec_583 ,mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
for (f65 = f66, f65_p_0 = 0;
	f65 < f66 + 512;
	f65 += 512, f65_p_0 += 512){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x65 = x66, x65_p_0 = 0;
		x65 < x66 + 17;
		x65 += 17, x65_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 2) (1024 / 512)
		for (c48 = c49, c48_p_0 = 0;
			c48 < c49 + 1024;
			c48 += 512, c48_p_0 += 512){
			// y = 17, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (f, 8) (512 / 64)
			for (f64 = f65, f64_p_1 = f65_p_0, f64_p_0 = 0;
				f64 < f65 + 512;
				f64 += 64, f64_p_1 += 64, f64_p_0 += 64){
					for (y = y32, yp_0 = 0;
						y < y32 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
						// T (x, 1) (17 / 17)
						for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
							x64 < x65 + 17;
							x64 += 17, x64_p_1 += 17, x64_p_0 += 17){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
							// T (f, 2) (64 / 32)
							for (f = f64, fp_2 = f64_p_1, fp_1 = f64_p_0, fp_0 = 0;
								f < f64 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
								// T (x, 17) (17 / 1)
								for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
									x < x64 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_576 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_577 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_578 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_579 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_576);
												mem_vec_576 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_577);
												mem_vec_577 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_578);
												mem_vec_578 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_579);
												mem_vec_579 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_580);
												mem_vec_580 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_581);
												mem_vec_581 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_582);
												mem_vec_582 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_583);
												mem_vec_583 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_584);
												mem_vec_584 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_585);
												mem_vec_585 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_586);
												mem_vec_586 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_587);
												mem_vec_587 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_588);
												mem_vec_588 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_589);
												mem_vec_589 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_590);
												mem_vec_590 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_591);
												mem_vec_591 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_576);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_577);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_578);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_579);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_580);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_581);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_582);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_583);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_584);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_585);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_586);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_587);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_588);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_589);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_590);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_591);
								}
							}
						}
					}
					for (y = y32 + 12, yp_0 = 0;
						y < y32 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
						// T (x, 1) (17 / 17)
						for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
							x64 < x65 + 17;
							x64 += 17, x64_p_1 += 17, x64_p_0 += 17){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
							// T (f, 2) (64 / 32)
							for (f = f64, fp_2 = f64_p_1, fp_1 = f64_p_0, fp_0 = 0;
								f < f64 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
								// T (x, 17) (17 / 1)
								for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
									x < x64 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_592 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_593 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_594 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_595 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_592);
												mem_vec_592 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_593);
												mem_vec_593 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_594);
												mem_vec_594 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_595);
												mem_vec_595 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_596);
												mem_vec_596 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_597);
												mem_vec_597 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_598);
												mem_vec_598 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_599);
												mem_vec_599 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_600);
												mem_vec_600 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_601);
												mem_vec_601 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_602);
												mem_vec_602 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_603);
												mem_vec_603 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_604);
												mem_vec_604 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_605);
												mem_vec_605 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_606);
												mem_vec_606 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_607);
												mem_vec_607 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_608);
												mem_vec_608 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_609);
												mem_vec_609 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_610);
												mem_vec_610 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_611);
												mem_vec_611 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_592);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_593);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_594);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_595);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_596);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_597);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_598);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_599);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_600);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_601);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_602);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_603);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_604);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_605);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_606);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_607);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_608);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_609);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_610);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_611);
								}
							}
						}
					}
			}
		}
	}
}


}