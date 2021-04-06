#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (1, f); T (14, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 1), (Arg 5))]; T (4, f);
  T (2, c); T (4, f)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, f, f0, fp_0, f0_p_0, f1_p_0, f1, fp_1, f0_p_1, fp_2, w, wp_0, x, x0, xp_0, x0_p_0, xp_1, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y0 = 0;
IND_TYPE x1 = 0;
IND_TYPE h = 0;
IND_TYPE w0 = 0;
IND_TYPE c1 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_10 ,mem_vec_11 ,mem_vec_12 ,mem_vec_13 ,mem_vec_14 ,mem_vec_15 ,mem_vec_16 ,mem_vec_17 ,mem_vec_18 ,mem_vec_19 ,mem_vec_2 ,mem_vec_20 ,mem_vec_21 ,mem_vec_22 ,mem_vec_23 ,mem_vec_24 ,mem_vec_25 ,mem_vec_26 ,mem_vec_27 ,mem_vec_28 ,mem_vec_29 ,mem_vec_3 ,mem_vec_30 ,mem_vec_31 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,mem_vec_8 ,mem_vec_9 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
for (f1 = f2, f1_p_0 = 0;
	f1 < f2 + 512;
	f1 += 128, f1_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 128
	// T (c, 2) (512 / 256)
	for (c0 = c1, c0_p_0 = 0;
		c0 < c1 + 512;
		c0 += 256, c0_p_0 += 256){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f0 = f1, f0_p_1 = f1_p_0, f0_p_0 = 0;
			f0 < f1 + 128;
			f0 += 32, f0_p_1 += 32, f0_p_0 += 32){
				for (y = y0, yp_0 = 0;
					y < y0 + 9;
					y += 3, yp_0 += 3){
					// y = u_y, x = 14, h = 3, w = 3, c = 256, f = 32
					// T (x, 14) (14 / 1)
					for (x0 = x1, x0_p_0 = 0;
						x0 < x1 + 14;
						x0 += 1, x0_p_0 += 1){
						// y = u_y, x = 1, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f0, fp_2 = f0_p_1, fp_1 = f0_p_0, fp_0 = 0;
							f < f0 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = u_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (w, 3) (3 / 1)
							for (w = w0, wp_0 = 0;
								w < w0 + 3;
								w += 1, wp_0 += 1){
								// y = u_y, x = 1, h = 3, w = 1, c = 256, f = 32
								// T (x, 1) (1 / 1)
								for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
									x < x0 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_0 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_2 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_4 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											// y = u_y, x = 1, h = 3, w = 1, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
												c < c0 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_0);
												mem_vec_0 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1);
												mem_vec_1 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2);
												mem_vec_2 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3);
												mem_vec_3 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4);
												mem_vec_4 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5);
												mem_vec_5 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6);
												mem_vec_6 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7);
												mem_vec_7 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8);
												mem_vec_8 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9);
												mem_vec_9 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10);
												mem_vec_10 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11);
												mem_vec_11 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_20 = _mm256_set1_ps(scal_3);
												vec_21 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_19 = _mm256_fmadd_ps(vec_20, vec_21, mem_vec_0);
												mem_vec_0 = vec_19;

												vec_23 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_22 = _mm256_fmadd_ps(vec_20, vec_23, mem_vec_1);
												mem_vec_1 = vec_22;

												vec_25 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_24 = _mm256_fmadd_ps(vec_20, vec_25, mem_vec_2);
												mem_vec_2 = vec_24;

												vec_27 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_26 = _mm256_fmadd_ps(vec_20, vec_27, mem_vec_3);
												mem_vec_3 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_29 = _mm256_set1_ps(scal_4);


												vec_28 = _mm256_fmadd_ps(vec_29, vec_21, mem_vec_4);
												mem_vec_4 = vec_28;



												vec_30 = _mm256_fmadd_ps(vec_29, vec_23, mem_vec_5);
												mem_vec_5 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_29, vec_25, mem_vec_6);
												mem_vec_6 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_29, vec_27, mem_vec_7);
												mem_vec_7 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_21, mem_vec_8);
												mem_vec_8 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_23, mem_vec_9);
												mem_vec_9 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_25, mem_vec_10);
												mem_vec_10 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_27, mem_vec_11);
												mem_vec_11 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_39 = _mm256_set1_ps(scal_6);
												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_0);
												mem_vec_0 = vec_38;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_1);
												mem_vec_1 = vec_41;

												vec_44 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_43 = _mm256_fmadd_ps(vec_39, vec_44, mem_vec_2);
												mem_vec_2 = vec_43;

												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_45 = _mm256_fmadd_ps(vec_39, vec_46, mem_vec_3);
												mem_vec_3 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_48 = _mm256_set1_ps(scal_7);


												vec_47 = _mm256_fmadd_ps(vec_48, vec_40, mem_vec_4);
												mem_vec_4 = vec_47;



												vec_49 = _mm256_fmadd_ps(vec_48, vec_42, mem_vec_5);
												mem_vec_5 = vec_49;



												vec_50 = _mm256_fmadd_ps(vec_48, vec_44, mem_vec_6);
												mem_vec_6 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_48, vec_46, mem_vec_7);
												mem_vec_7 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_8);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_8);
												mem_vec_8 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_9);
												mem_vec_9 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_44, mem_vec_10);
												mem_vec_10 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_46, mem_vec_11);
												mem_vec_11 = vec_56;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11);
								}
							}
						}
					}
				}
				for (y = y0 + 9, yp_0 = 0;
					y < y0 + 9 + 5;
					y += 5, yp_0 += 5){
					// y = u_y, x = 14, h = 3, w = 3, c = 256, f = 32
					// T (x, 14) (14 / 1)
					for (x0 = x1, x0_p_0 = 0;
						x0 < x1 + 14;
						x0 += 1, x0_p_0 += 1){
						// y = u_y, x = 1, h = 3, w = 3, c = 256, f = 32
						// T (f, 1) (32 / 32)
						for (f = f0, fp_2 = f0_p_1, fp_1 = f0_p_0, fp_0 = 0;
							f < f0 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = u_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (w, 3) (3 / 1)
							for (w = w0, wp_0 = 0;
								w < w0 + 3;
								w += 1, wp_0 += 1){
								// y = u_y, x = 1, h = 3, w = 1, c = 256, f = 32
								// T (x, 1) (1 / 1)
								for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
									x < x0 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_14 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_15 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_16 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_17 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_18 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_19 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_20 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_21 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_22 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_23 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_24 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_25 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_26 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_27 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_28 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_29 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_30 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_31 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = u_y, x = 1, h = 3, w = 1, c = 256, f = 32
											// T (c, 256) (256 / 1)
											for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
												c < c0 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12);
												mem_vec_12 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13);
												mem_vec_13 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14);
												mem_vec_14 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15);
												mem_vec_15 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_16);
												mem_vec_16 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_17);
												mem_vec_17 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_18);
												mem_vec_18 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_19);
												mem_vec_19 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_20);
												mem_vec_20 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_21);
												mem_vec_21 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_22);
												mem_vec_22 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_23);
												mem_vec_23 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_24);
												mem_vec_24 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_25);
												mem_vec_25 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_26);
												mem_vec_26 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_27);
												mem_vec_27 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_28);
												mem_vec_28 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_29);
												mem_vec_29 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_30);
												mem_vec_30 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_31);
												mem_vec_31 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_12);
												mem_vec_12 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_13);
												mem_vec_13 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_14);
												mem_vec_14 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_15);
												mem_vec_15 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_16);
												mem_vec_16 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_17);
												mem_vec_17 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_18);
												mem_vec_18 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_19);
												mem_vec_19 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_20);
												mem_vec_20 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_21);
												mem_vec_21 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_22);
												mem_vec_22 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_23);
												mem_vec_23 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_24);
												mem_vec_24 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_25);
												mem_vec_25 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_26);
												mem_vec_26 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_27);
												mem_vec_27 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_28);
												mem_vec_28 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_29);
												mem_vec_29 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_30);
												mem_vec_30 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_31);
												mem_vec_31 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_12);
												mem_vec_12 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_13);
												mem_vec_13 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_14);
												mem_vec_14 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_15);
												mem_vec_15 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_16);
												mem_vec_16 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_17);
												mem_vec_17 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_18);
												mem_vec_18 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_19);
												mem_vec_19 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_20);
												mem_vec_20 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_21);
												mem_vec_21 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_22);
												mem_vec_22 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_23);
												mem_vec_23 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_24);
												mem_vec_24 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_25);
												mem_vec_25 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_26);
												mem_vec_26 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_27);
												mem_vec_27 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_28);
												mem_vec_28 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_29);
												mem_vec_29 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_30);
												mem_vec_30 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_31);
												mem_vec_31 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_17);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_18);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_19);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_20);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_21);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_22);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_23);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_24);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_25);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_26);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_27);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_28);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_29);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_30);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_31);
								}
							}
						}
					}
				}
		}
	}
}


}