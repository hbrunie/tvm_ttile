#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (128, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c666_p_0, cp_1, c666, f, fp_0, f888_p_0, f889_p_0, fp_1, f888_p_1, fp_2, f888, f889, x, xp_0, x888_p_0, x889_p_0, xp_1, x888_p_1, xp_2, x888, x889, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y444 = 0;
IND_TYPE x890 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c667 = 0;
IND_TYPE f890 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_7992 ,mem_vec_7993 ,mem_vec_7994 ,mem_vec_7995 ,mem_vec_7996 ,mem_vec_7997 ,mem_vec_7998 ,mem_vec_7999 ,mem_vec_8000 ,mem_vec_8001 ,mem_vec_8002 ,mem_vec_8003 ,mem_vec_8004 ,mem_vec_8005 ,mem_vec_8006 ,mem_vec_8007 ,mem_vec_8008 ,mem_vec_8009 ,mem_vec_8010 ,mem_vec_8011 ,mem_vec_8012 ,mem_vec_8013 ,mem_vec_8014 ,mem_vec_8015 ,mem_vec_8016 ,mem_vec_8017 ,mem_vec_8018 ,mem_vec_8019 ,mem_vec_8020 ,mem_vec_8021 ,mem_vec_8022 ,mem_vec_8023 ,mem_vec_8024 ,mem_vec_8025 ,mem_vec_8026 ,mem_vec_8027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
for (f889 = f890, f889_p_0 = 0;
	f889 < f890 + 512;
	f889 += 512, f889_p_0 += 512){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x889 = x890, x889_p_0 = 0;
		x889 < x890 + 17;
		x889 += 17, x889_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 128) (1024 / 8)
		for (c666 = c667, c666_p_0 = 0;
			c666 < c667 + 1024;
			c666 += 8, c666_p_0 += 8){
			// y = 17, x = 17, h = 1, w = 1, c = 8, f = 512
			// T (f, 8) (512 / 64)
			for (f888 = f889, f888_p_1 = f889_p_0, f888_p_0 = 0;
				f888 < f889 + 512;
				f888 += 64, f888_p_1 += 64, f888_p_0 += 64){
					for (y = y444, yp_0 = 0;
						y < y444 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
						// T (x, 17) (17 / 1)
						for (x888 = x889, x888_p_1 = x889_p_0, x888_p_0 = 0;
							x888 < x889 + 17;
							x888 += 1, x888_p_1 += 1, x888_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
							// T (f, 2) (64 / 32)
							for (f = f888, fp_2 = f888_p_1, fp_1 = f888_p_0, fp_0 = 0;
								f < f888 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x888, xp_2 = x888_p_1, xp_1 = x888_p_0, xp_0 = 0;
									x < x888 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7992 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7993 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7994 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7995 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8000 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8001 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8002 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8003 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8004 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8005 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8006 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8007 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c666, cp_1 = c666_p_0, cp_0 = 0;
												c < c666 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7992);
												mem_vec_7992 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7993);
												mem_vec_7993 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7994);
												mem_vec_7994 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7995);
												mem_vec_7995 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7996);
												mem_vec_7996 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7997);
												mem_vec_7997 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7998);
												mem_vec_7998 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7999);
												mem_vec_7999 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8000);
												mem_vec_8000 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8001);
												mem_vec_8001 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8002);
												mem_vec_8002 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8003);
												mem_vec_8003 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8004);
												mem_vec_8004 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8005);
												mem_vec_8005 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8006);
												mem_vec_8006 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8007);
												mem_vec_8007 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7992);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7993);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7994);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7995);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7996);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7997);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7998);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7999);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8000);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8001);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8002);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8003);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8004);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8005);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8006);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8007);
								}
							}
						}
					}
					for (y = y444 + 12, yp_0 = 0;
						y < y444 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
						// T (x, 17) (17 / 1)
						for (x888 = x889, x888_p_1 = x889_p_0, x888_p_0 = 0;
							x888 < x889 + 17;
							x888 += 1, x888_p_1 += 1, x888_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
							// T (f, 2) (64 / 32)
							for (f = f888, fp_2 = f888_p_1, fp_1 = f888_p_0, fp_0 = 0;
								f < f888 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x888, xp_2 = x888_p_1, xp_1 = x888_p_0, xp_0 = 0;
									x < x888 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8008 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8009 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_8010 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8011 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_8012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_8014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_8016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_8018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_8020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_8022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_8024 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8025 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_8026 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8027 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c666, cp_1 = c666_p_0, cp_0 = 0;
												c < c666 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8008);
												mem_vec_8008 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8009);
												mem_vec_8009 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8010);
												mem_vec_8010 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8011);
												mem_vec_8011 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8012);
												mem_vec_8012 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8013);
												mem_vec_8013 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8014);
												mem_vec_8014 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8015);
												mem_vec_8015 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8016);
												mem_vec_8016 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8017);
												mem_vec_8017 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8018);
												mem_vec_8018 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8019);
												mem_vec_8019 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8020);
												mem_vec_8020 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8021);
												mem_vec_8021 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8022);
												mem_vec_8022 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8023);
												mem_vec_8023 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8024);
												mem_vec_8024 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8025);
												mem_vec_8025 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8026);
												mem_vec_8026 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8027);
												mem_vec_8027 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8008);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8009);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8010);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8011);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8012);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8013);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8014);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8015);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8016);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8017);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8018);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8019);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8020);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8021);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8022);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8023);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8024);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8025);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8026);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8027);
								}
							}
						}
					}
			}
		}
	}
}


}