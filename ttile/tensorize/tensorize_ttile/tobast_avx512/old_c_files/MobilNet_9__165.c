#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (1, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (2, c);
  T (16, f); T (8, c)]
*/
IND_TYPE c, cp_0, c1508_p_0, c1509_p_0, c1510_p_0, cp_1, c1508_p_1, c1509_p_1, cp_2, c1508_p_2, cp_3, c1508, c1509, c1510, f, fp_0, f1020_p_0, fp_1, f1020, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y486 = 0;
IND_TYPE x632 = 0;
IND_TYPE h = 0;
IND_TYPE w512 = 0;
IND_TYPE c1511 = 0;
IND_TYPE f1021 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5804 ,mem_vec_5805 ,mem_vec_5806 ,mem_vec_5807 ,mem_vec_5808 ,mem_vec_5809 ,mem_vec_5810 ,mem_vec_5811 ,mem_vec_5812 ,mem_vec_5813 ,mem_vec_5814 ,mem_vec_5815 ,mem_vec_5816 ,mem_vec_5817 ,mem_vec_5818 ,mem_vec_5819 ,mem_vec_5820 ,mem_vec_5821 ,mem_vec_5822 ,mem_vec_5823 ,mem_vec_5824 ,mem_vec_5825 ,mem_vec_5826 ,mem_vec_5827 ,mem_vec_5828 ,mem_vec_5829 ,mem_vec_5830 ,mem_vec_5831 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c1510 = c1511, c1510_p_0 = 0;
	c1510 < c1511 + 1024;
	c1510 += 128, c1510_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (f, 16) (1024 / 64)
	for (f1020 = f1021, f1020_p_0 = 0;
		f1020 < f1021 + 1024;
		f1020 += 64, f1020_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 128, f = 64
		// T (c, 2) (128 / 64)
		for (c1509 = c1510, c1509_p_1 = c1510_p_0, c1509_p_0 = 0;
			c1509 < c1510 + 128;
			c1509 += 64, c1509_p_1 += 64, c1509_p_0 += 64){
				for (y = y486, yp_0 = 0;
					y < y486 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1020, fp_1 = f1020_p_0, fp_0 = 0;
						f < f1020 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (c, 1) (64 / 64)
						for (c1508 = c1509, c1508_p_2 = c1509_p_1, c1508_p_1 = c1509_p_0, c1508_p_0 = 0;
							c1508 < c1509 + 64;
							c1508 += 64, c1508_p_2 += 64, c1508_p_1 += 64, c1508_p_0 += 64){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
							// T (w, 3) (3 / 1)
							for (w = w512, wp_0 = 0;
								w < w512 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 64
								// T (x, 7) (7 / 1)
								for (x = x632, xp_0 = 0;
									x < x632 + 7;
									x += 1, xp_0 += 1){
											mem_vec_5804 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5805 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5806 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5807 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c1508, cp_3 = c1508_p_2, cp_2 = c1508_p_1, cp_1 = c1508_p_0, cp_0 = 0;
												c < c1508 + 64;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5804);
												mem_vec_5804 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5805);
												mem_vec_5805 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5806);
												mem_vec_5806 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5807);
												mem_vec_5807 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5808);
												mem_vec_5808 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5809);
												mem_vec_5809 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5810);
												mem_vec_5810 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5811);
												mem_vec_5811 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5812);
												mem_vec_5812 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5813);
												mem_vec_5813 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5814);
												mem_vec_5814 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5815);
												mem_vec_5815 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_5804);
												mem_vec_5804 = vec_19;

												vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_5805);
												mem_vec_5805 = vec_22;

												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_5806);
												mem_vec_5806 = vec_24;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_5807);
												mem_vec_5807 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_4);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5808);
												mem_vec_5808 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_5809);
												mem_vec_5809 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_5810);
												mem_vec_5810 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_5811);
												mem_vec_5811 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_5812);
												mem_vec_5812 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_5813);
												mem_vec_5813 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_5814);
												mem_vec_5814 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_5815);
												mem_vec_5815 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_5804);
												mem_vec_5804 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_5805);
												mem_vec_5805 = vec_41;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_5806);
												mem_vec_5806 = vec_43;

												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_5807);
												mem_vec_5807 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_48 = _mm512_set1_ps(scal_7);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_5808);
												mem_vec_5808 = vec_47;



												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_5809);
												mem_vec_5809 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_5810);
												mem_vec_5810 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_5811);
												mem_vec_5811 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_53 = _mm512_set1_ps(scal_8);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_5812);
												mem_vec_5812 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_5813);
												mem_vec_5813 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_5814);
												mem_vec_5814 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_5815);
												mem_vec_5815 = vec_56;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5815);
								}
							}
						}
					}
				}
				for (y = y486 + 3, yp_0 = 0;
					y < y486 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1020, fp_1 = f1020_p_0, fp_0 = 0;
						f < f1020 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (c, 1) (64 / 64)
						for (c1508 = c1509, c1508_p_2 = c1509_p_1, c1508_p_1 = c1509_p_0, c1508_p_0 = 0;
							c1508 < c1509 + 64;
							c1508 += 64, c1508_p_2 += 64, c1508_p_1 += 64, c1508_p_0 += 64){
							// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
							// T (w, 3) (3 / 1)
							for (w = w512, wp_0 = 0;
								w < w512 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 64
								// T (x, 7) (7 / 1)
								for (x = x632, xp_0 = 0;
									x < x632 + 7;
									x += 1, xp_0 += 1){
											mem_vec_5816 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5817 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5818 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_5819 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_5820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_5823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_5824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_5827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_5828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_5831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 64
											// T (c, 64) (64 / 1)
											for (c = c1508, cp_3 = c1508_p_2, cp_2 = c1508_p_1, cp_1 = c1508_p_0, cp_0 = 0;
												c < c1508 + 64;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5816);
												mem_vec_5816 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5817);
												mem_vec_5817 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5818);
												mem_vec_5818 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5819);
												mem_vec_5819 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5820);
												mem_vec_5820 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5821);
												mem_vec_5821 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5822);
												mem_vec_5822 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5823);
												mem_vec_5823 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5824);
												mem_vec_5824 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5825);
												mem_vec_5825 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5826);
												mem_vec_5826 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5827);
												mem_vec_5827 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5828);
												mem_vec_5828 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5829);
												mem_vec_5829 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5830);
												mem_vec_5830 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5831);
												mem_vec_5831 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_5816);
												mem_vec_5816 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_5817);
												mem_vec_5817 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_5818);
												mem_vec_5818 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_5819);
												mem_vec_5819 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_5820);
												mem_vec_5820 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_5821);
												mem_vec_5821 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_5822);
												mem_vec_5822 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_5823);
												mem_vec_5823 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_5824);
												mem_vec_5824 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_5825);
												mem_vec_5825 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_5826);
												mem_vec_5826 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_5827);
												mem_vec_5827 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_5828);
												mem_vec_5828 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_5829);
												mem_vec_5829 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_5830);
												mem_vec_5830 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_5831);
												mem_vec_5831 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_5816);
												mem_vec_5816 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_5817);
												mem_vec_5817 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_5818);
												mem_vec_5818 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_5819);
												mem_vec_5819 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_5820);
												mem_vec_5820 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_5821);
												mem_vec_5821 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_5822);
												mem_vec_5822 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_5823);
												mem_vec_5823 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_5824);
												mem_vec_5824 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_5825);
												mem_vec_5825 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_5826);
												mem_vec_5826 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_5827);
												mem_vec_5827 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_5828);
												mem_vec_5828 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_5829);
												mem_vec_5829 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_5830);
												mem_vec_5830 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_5831);
												mem_vec_5831 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5831);
								}
							}
						}
					}
				}
		}
	}
}


}