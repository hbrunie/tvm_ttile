#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (16, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (4, y); T (2, f); T (28, x); T (1, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, x, xp_0, x175_p_0, x176_p_0, x177_p_0, xp_1, x175_p_1, x176_p_1, xp_2, x175_p_2, xp_3, x175, x176, x177, y, yp_0, y140_p_0, y141_p_0, yp_1, y140_p_1, yp_2, y140, y141;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y142 = 0;
IND_TYPE x178 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c106 = 0;
IND_TYPE f70 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_584 ,mem_vec_585 ,mem_vec_586 ,mem_vec_587 ,mem_vec_588 ,mem_vec_589 ,mem_vec_590 ,mem_vec_591 ,mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y141 = y142, y141_p_0 = 0;
	y141 < y142 + 56;
	y141 += 56, y141_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 1) (56 / 56)
	for (x177 = x178, x177_p_0 = 0;
		x177 < x178 + 56;
		x177 += 56, x177_p_0 += 56){
		// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y140 = y141, y140_p_1 = y141_p_0, y140_p_0 = 0;
			y140 < y141 + 56;
			y140 += 56, y140_p_1 += 56, y140_p_0 += 56){
			// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 28) (56 / 2)
			for (x176 = x177, x176_p_1 = x177_p_0, x176_p_0 = 0;
				x176 < x177 + 56;
				x176 += 2, x176_p_1 += 2, x176_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f70, fp_0 = 0;
					f < f70 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 4) (56 / 14)
					for (y = y140, yp_2 = y140_p_1, yp_1 = y140_p_0, yp_0 = 0;
						y < y140 + 56;
						y += 14, yp_2 += 14, yp_1 += 14, yp_0 += 14){
						// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x175 = x176, x175_p_2 = x176_p_1, x175_p_1 = x176_p_0, x175_p_0 = 0;
							x175 < x176 + 2;
							x175 += 2, x175_p_2 += 2, x175_p_1 += 2, x175_p_0 += 2){
							// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c105 = c106, c105_p_0 = 0;
								c105 < c106 + 64;
								c105 += 16, c105_p_0 += 16){
								// y = 14, x = 2, h = 1, w = 1, c = 16, f = 32
								// T (x, 2) (2 / 1)
								for (x = x175, xp_3 = x175_p_2, xp_2 = x175_p_1, xp_1 = x175_p_0, xp_0 = 0;
									x < x175 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_584 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_585 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = 14, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
												c < c105 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_584);
												mem_vec_584 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_585);
												mem_vec_585 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_586);
												mem_vec_586 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_587);
												mem_vec_587 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_588);
												mem_vec_588 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_589);
												mem_vec_589 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_590);
												mem_vec_590 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_591);
												mem_vec_591 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_592);
												mem_vec_592 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_593);
												mem_vec_593 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_594);
												mem_vec_594 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_595);
												mem_vec_595 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_596);
												mem_vec_596 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_597);
												mem_vec_597 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_598);
												mem_vec_598 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_599);
												mem_vec_599 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_600);
												mem_vec_600 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_601);
												mem_vec_601 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_602);
												mem_vec_602 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_603);
												mem_vec_603 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_604);
												mem_vec_604 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_605);
												mem_vec_605 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_606);
												mem_vec_606 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_607);
												mem_vec_607 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_608);
												mem_vec_608 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_609);
												mem_vec_609 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_610);
												mem_vec_610 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_611);
												mem_vec_611 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_584);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_585);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_586);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_587);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_588);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_589);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_590);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_591);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_592);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_593);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_594);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_595);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_596);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_597);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_598);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_599);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_600);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_601);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_602);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_603);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_604);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_605);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_606);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_607);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_608);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_609);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_610);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_611);
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