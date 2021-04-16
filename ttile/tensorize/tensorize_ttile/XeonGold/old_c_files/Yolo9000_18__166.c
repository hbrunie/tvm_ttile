#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (32, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (1, c); T (1, c)]
*/
IND_TYPE c, cp_0, c5_p_0, c6_p_0, c7_p_0, cp_1, c5_p_1, c6_p_1, cp_2, c5_p_2, cp_3, c5, c6, c7, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y2 = 0;
IND_TYPE x2 = 0;
IND_TYPE h2 = 0;
IND_TYPE w2 = 0;
IND_TYPE c8 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,mem_vec_40 ,mem_vec_41 ,mem_vec_42 ,mem_vec_43 ,mem_vec_44 ,mem_vec_45 ,mem_vec_46 ,mem_vec_47 ,mem_vec_48 ,mem_vec_49 ,mem_vec_50 ,mem_vec_51 ,mem_vec_52 ,mem_vec_53 ,mem_vec_54 ,mem_vec_55 ,mem_vec_56 ,mem_vec_57 ,mem_vec_58 ,mem_vec_59 ,mem_vec_60 ,mem_vec_61 ,mem_vec_62 ,mem_vec_63 ,mem_vec_64 ,mem_vec_65 ,mem_vec_66 ,mem_vec_67 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c7 = c8, c7_p_0 = 0;
	c7 < c8 + 512;
	c7 += 512, c7_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 1) (512 / 512)
	for (c6 = c7, c6_p_1 = c7_p_0, c6_p_0 = 0;
		c6 < c7 + 512;
		c6 += 512, c6_p_1 += 512, c6_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f2, fp_0 = 0;
			f < f2 + 1024;
			f += 32, fp_0 += 32){
				for (y = y2, yp_0 = 0;
					y < y2 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
					// T (c, 32) (512 / 16)
					for (c5 = c6, c5_p_2 = c6_p_1, c5_p_1 = c6_p_0, c5_p_0 = 0;
						c5 < c6 + 512;
						c5 += 16, c5_p_2 += 16, c5_p_1 += 16, c5_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x2, xp_0 = 0;
							x < x2 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h2, hp_0 = 0;
								h < h2 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w2, wp_0 = 0;
									w < w2 + 3;
									w += 1, wp_0 += 1){
											mem_vec_34 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_35 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_36 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_37 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_38 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_39 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_40 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_41 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_42 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_43 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_44 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_45 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_46 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_47 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_48 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_49 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c5, cp_3 = c5_p_2, cp_2 = c5_p_1, cp_1 = c5_p_0, cp_0 = 0;
												c < c5 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_34);
												mem_vec_34 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_35);
												mem_vec_35 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_36);
												mem_vec_36 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_37);
												mem_vec_37 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_38);
												mem_vec_38 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_39);
												mem_vec_39 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_40);
												mem_vec_40 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_41);
												mem_vec_41 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_42);
												mem_vec_42 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_43);
												mem_vec_43 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_44);
												mem_vec_44 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_45);
												mem_vec_45 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_46);
												mem_vec_46 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_47);
												mem_vec_47 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_48);
												mem_vec_48 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_49);
												mem_vec_49 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_34);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_35);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_36);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_37);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_38);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_39);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_40);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_41);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_42);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_43);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_44);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_45);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_46);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_47);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_48);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_49);
								}
							}
						}
					}
				}
				for (y = y2 + 8, yp_0 = 0;
					y < y2 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
					// T (c, 32) (512 / 16)
					for (c5 = c6, c5_p_2 = c6_p_1, c5_p_1 = c6_p_0, c5_p_0 = 0;
						c5 < c6 + 512;
						c5 += 16, c5_p_2 += 16, c5_p_1 += 16, c5_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x2, xp_0 = 0;
							x < x2 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h2, hp_0 = 0;
								h < h2 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w2, wp_0 = 0;
									w < w2 + 3;
									w += 1, wp_0 += 1){
											mem_vec_50 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_51 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_52 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_53 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_54 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_55 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_56 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_57 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_58 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_59 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_60 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_61 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_62 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_63 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_64 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_65 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_66 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_67 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c5, cp_3 = c5_p_2, cp_2 = c5_p_1, cp_1 = c5_p_0, cp_0 = 0;
												c < c5 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_50);
												mem_vec_50 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_51);
												mem_vec_51 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_52);
												mem_vec_52 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_53);
												mem_vec_53 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_54);
												mem_vec_54 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_55);
												mem_vec_55 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_56);
												mem_vec_56 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_57);
												mem_vec_57 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_58);
												mem_vec_58 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_59);
												mem_vec_59 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_60);
												mem_vec_60 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_61);
												mem_vec_61 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_62);
												mem_vec_62 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_63);
												mem_vec_63 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_64);
												mem_vec_64 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_65);
												mem_vec_65 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_66);
												mem_vec_66 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_67);
												mem_vec_67 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_50);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_51);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_52);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_53);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_54);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_55);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_56);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_57);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_58);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_59);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_60);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_61);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_62);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_63);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_64);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_65);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_66);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_67);
								}
							}
						}
					}
				}
		}
	}
}


}