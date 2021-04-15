#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (4, x); T (17, y); T (1, f); T (32, c); T (17, x);
  T (4, f)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, f136_p_0, f137_p_0, fp_1, f136_p_1, fp_2, f136, f137, h, hp_0, x, xp_0, x136_p_0, x137_p_0, xp_1, x136_p_1, xp_2, x136, x137, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y68 = 0;
IND_TYPE x138 = 0;
IND_TYPE h68 = 0;
IND_TYPE w = 0;
IND_TYPE c103 = 0;
IND_TYPE f138 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_544 ,mem_vec_545 ,mem_vec_546 ,mem_vec_547 ,mem_vec_548 ,mem_vec_549 ,mem_vec_550 ,mem_vec_551 ,mem_vec_552 ,mem_vec_553 ,mem_vec_554 ,mem_vec_555 ,mem_vec_556 ,mem_vec_557 ,mem_vec_558 ,mem_vec_559 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f137 = f138, f137_p_0 = 0;
	f137 < f138 + 256;
	f137 += 64, f137_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (x, 17) (68 / 4)
	for (x137 = x138, x137_p_0 = 0;
		x137 < x138 + 68;
		x137 += 4, x137_p_0 += 4){
		// y = 68, x = 4, h = 3, w = 3, c = 128, f = 64
		// T (c, 32) (128 / 4)
		for (c102 = c103, c102_p_0 = 0;
			c102 < c103 + 128;
			c102 += 4, c102_p_0 += 4){
			// y = 68, x = 4, h = 3, w = 3, c = 4, f = 64
			// T (f, 1) (64 / 64)
			for (f136 = f137, f136_p_1 = f137_p_0, f136_p_0 = 0;
				f136 < f137 + 64;
				f136 += 64, f136_p_1 += 64, f136_p_0 += 64){
				// y = 68, x = 4, h = 3, w = 3, c = 4, f = 64
				// T (y, 17) (68 / 4)
				for (y = y68, yp_0 = 0;
					y < y68 + 68;
					y += 4, yp_0 += 4){
					// y = 4, x = 4, h = 3, w = 3, c = 4, f = 64
					// T (x, 4) (4 / 1)
					for (x136 = x137, x136_p_1 = x137_p_0, x136_p_0 = 0;
						x136 < x137 + 4;
						x136 += 1, x136_p_1 += 1, x136_p_0 += 1){
						// y = 4, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (f, 1) (64 / 64)
						for (f = f136, fp_2 = f136_p_1, fp_1 = f136_p_0, fp_0 = 0;
							f < f136 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = 4, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h68, hp_0 = 0;
								h < h68 + 3;
								h += 1, hp_0 += 1){
								// y = 4, x = 1, h = 1, w = 3, c = 4, f = 64
								// T (x, 1) (1 / 1)
								for (x = x136, xp_2 = x136_p_1, xp_1 = x136_p_0, xp_0 = 0;
									x < x136 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_544 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_545 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_546 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_547 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = 4, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
												c < c102 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_544);
												mem_vec_544 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_545);
												mem_vec_545 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_546);
												mem_vec_546 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_547);
												mem_vec_547 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_548);
												mem_vec_548 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_549);
												mem_vec_549 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_550);
												mem_vec_550 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_551);
												mem_vec_551 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_552);
												mem_vec_552 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_553);
												mem_vec_553 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_554);
												mem_vec_554 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_555);
												mem_vec_555 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_556);
												mem_vec_556 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_557);
												mem_vec_557 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_558);
												mem_vec_558 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_559);
												mem_vec_559 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_544);
												mem_vec_544 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_545);
												mem_vec_545 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_546);
												mem_vec_546 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_547);
												mem_vec_547 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_548);
												mem_vec_548 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_549);
												mem_vec_549 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_550);
												mem_vec_550 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_551);
												mem_vec_551 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_552);
												mem_vec_552 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_553);
												mem_vec_553 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_554);
												mem_vec_554 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_555);
												mem_vec_555 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_556);
												mem_vec_556 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_557);
												mem_vec_557 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_558);
												mem_vec_558 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_559);
												mem_vec_559 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_544);
												mem_vec_544 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_545);
												mem_vec_545 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_546);
												mem_vec_546 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_547);
												mem_vec_547 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_548);
												mem_vec_548 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_549);
												mem_vec_549 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_550);
												mem_vec_550 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_551);
												mem_vec_551 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_552);
												mem_vec_552 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_553);
												mem_vec_553 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_554);
												mem_vec_554 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_555);
												mem_vec_555 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_556);
												mem_vec_556 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_557);
												mem_vec_557 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_558);
												mem_vec_558 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_559);
												mem_vec_559 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_544);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_545);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_546);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_547);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_548);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_549);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_550);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_551);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_552);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_553);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_554);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_555);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_556);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_557);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_558);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_559);
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