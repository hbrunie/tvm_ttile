#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (16, f);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (512, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, f, fp_0, f1016_p_0, f1017_p_0, fp_1, f1016_p_1, fp_2, f1016, f1017, x, xp_0, x1016_p_0, x1017_p_0, xp_1, x1016_p_1, xp_2, x1016, x1017, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y508 = 0;
IND_TYPE x1018 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c763 = 0;
IND_TYPE f1018 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_9144 ,mem_vec_9145 ,mem_vec_9146 ,mem_vec_9147 ,mem_vec_9148 ,mem_vec_9149 ,mem_vec_9150 ,mem_vec_9151 ,mem_vec_9152 ,mem_vec_9153 ,mem_vec_9154 ,mem_vec_9155 ,mem_vec_9156 ,mem_vec_9157 ,mem_vec_9158 ,mem_vec_9159 ,mem_vec_9160 ,mem_vec_9161 ,mem_vec_9162 ,mem_vec_9163 ,mem_vec_9164 ,mem_vec_9165 ,mem_vec_9166 ,mem_vec_9167 ,mem_vec_9168 ,mem_vec_9169 ,mem_vec_9170 ,mem_vec_9171 ,mem_vec_9172 ,mem_vec_9173 ,mem_vec_9174 ,mem_vec_9175 ,mem_vec_9176 ,mem_vec_9177 ,mem_vec_9178 ,mem_vec_9179 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 1) (512 / 512)
for (f1017 = f1018, f1017_p_0 = 0;
	f1017 < f1018 + 512;
	f1017 += 512, f1017_p_0 += 512){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x1017 = x1018, x1017_p_0 = 0;
		x1017 < x1018 + 17;
		x1017 += 17, x1017_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 512) (1024 / 2)
		for (c762 = c763, c762_p_0 = 0;
			c762 < c763 + 1024;
			c762 += 2, c762_p_0 += 2){
			// y = 17, x = 17, h = 1, w = 1, c = 2, f = 512
			// T (f, 1) (512 / 512)
			for (f1016 = f1017, f1016_p_1 = f1017_p_0, f1016_p_0 = 0;
				f1016 < f1017 + 512;
				f1016 += 512, f1016_p_1 += 512, f1016_p_0 += 512){
					for (y = y508, yp_0 = 0;
						y < y508 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 512
						// T (x, 17) (17 / 1)
						for (x1016 = x1017, x1016_p_1 = x1017_p_0, x1016_p_0 = 0;
							x1016 < x1017 + 17;
							x1016 += 1, x1016_p_1 += 1, x1016_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 512
							// T (f, 16) (512 / 32)
							for (f = f1016, fp_2 = f1016_p_1, fp_1 = f1016_p_0, fp_0 = 0;
								f < f1016 + 512;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1016, xp_2 = x1016_p_1, xp_1 = x1016_p_0, xp_0 = 0;
									x < x1016 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9144 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9145 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9146 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9147 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
												c < c762 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9144);
												mem_vec_9144 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9145);
												mem_vec_9145 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9146);
												mem_vec_9146 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9147);
												mem_vec_9147 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9148);
												mem_vec_9148 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9149);
												mem_vec_9149 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9150);
												mem_vec_9150 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9151);
												mem_vec_9151 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9152);
												mem_vec_9152 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9153);
												mem_vec_9153 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9154);
												mem_vec_9154 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9155);
												mem_vec_9155 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9156);
												mem_vec_9156 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9157);
												mem_vec_9157 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9158);
												mem_vec_9158 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9159);
												mem_vec_9159 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9144);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9145);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9146);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9147);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9148);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9149);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9150);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9151);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9152);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9153);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9154);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9155);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9156);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9157);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9158);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9159);
								}
							}
						}
					}
					for (y = y508 + 12, yp_0 = 0;
						y < y508 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 512
						// T (x, 17) (17 / 1)
						for (x1016 = x1017, x1016_p_1 = x1017_p_0, x1016_p_0 = 0;
							x1016 < x1017 + 17;
							x1016 += 1, x1016_p_1 += 1, x1016_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 512
							// T (f, 16) (512 / 32)
							for (f = f1016, fp_2 = f1016_p_1, fp_1 = f1016_p_0, fp_0 = 0;
								f < f1016 + 512;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1016, xp_2 = x1016_p_1, xp_1 = x1016_p_0, xp_0 = 0;
									x < x1016 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9160 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9161 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_9172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_9174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_9176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_9178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
												c < c762 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9160);
												mem_vec_9160 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9161);
												mem_vec_9161 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9162);
												mem_vec_9162 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9163);
												mem_vec_9163 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9164);
												mem_vec_9164 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9165);
												mem_vec_9165 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9166);
												mem_vec_9166 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9167);
												mem_vec_9167 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9168);
												mem_vec_9168 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9169);
												mem_vec_9169 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9170);
												mem_vec_9170 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9171);
												mem_vec_9171 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9172);
												mem_vec_9172 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9173);
												mem_vec_9173 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9174);
												mem_vec_9174 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9175);
												mem_vec_9175 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9176);
												mem_vec_9176 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9177);
												mem_vec_9177 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9178);
												mem_vec_9178 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9179);
												mem_vec_9179 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9160);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9161);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9175);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9176);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9177);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9178);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9179);
								}
							}
						}
					}
			}
		}
	}
}


}