#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (1, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (16, c); T (17, x); T (8, f)]
*/
IND_TYPE c, cp_0, c1014_p_0, cp_1, c1014, f, fp_0, f1352_p_0, f1353_p_0, fp_1, f1352_p_1, fp_2, f1352, f1353, x, xp_0, x1352_p_0, x1353_p_0, xp_1, x1352_p_1, xp_2, x1352, x1353, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y676 = 0;
IND_TYPE x1354 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1015 = 0;
IND_TYPE f1354 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12168 ,mem_vec_12169 ,mem_vec_12170 ,mem_vec_12171 ,mem_vec_12172 ,mem_vec_12173 ,mem_vec_12174 ,mem_vec_12175 ,mem_vec_12176 ,mem_vec_12177 ,mem_vec_12178 ,mem_vec_12179 ,mem_vec_12180 ,mem_vec_12181 ,mem_vec_12182 ,mem_vec_12183 ,mem_vec_12184 ,mem_vec_12185 ,mem_vec_12186 ,mem_vec_12187 ,mem_vec_12188 ,mem_vec_12189 ,mem_vec_12190 ,mem_vec_12191 ,mem_vec_12192 ,mem_vec_12193 ,mem_vec_12194 ,mem_vec_12195 ,mem_vec_12196 ,mem_vec_12197 ,mem_vec_12198 ,mem_vec_12199 ,mem_vec_12200 ,mem_vec_12201 ,mem_vec_12202 ,mem_vec_12203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
for (f1353 = f1354, f1353_p_0 = 0;
	f1353 < f1354 + 512;
	f1353 += 64, f1353_p_0 += 64){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
	// T (x, 17) (17 / 1)
	for (x1353 = x1354, x1353_p_0 = 0;
		x1353 < x1354 + 17;
		x1353 += 1, x1353_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 64
		// T (c, 16) (1024 / 64)
		for (c1014 = c1015, c1014_p_0 = 0;
			c1014 < c1015 + 1024;
			c1014 += 64, c1014_p_0 += 64){
			// y = 17, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f1352 = f1353, f1352_p_1 = f1353_p_0, f1352_p_0 = 0;
				f1352 < f1353 + 64;
				f1352 += 32, f1352_p_1 += 32, f1352_p_0 += 32){
					for (y = y676, yp_0 = 0;
						y < y676 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x1352 = x1353, x1352_p_1 = x1353_p_0, x1352_p_0 = 0;
							x1352 < x1353 + 1;
							x1352 += 1, x1352_p_1 += 1, x1352_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1352, fp_2 = f1352_p_1, fp_1 = f1352_p_0, fp_0 = 0;
								f < f1352 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1352, xp_2 = x1352_p_1, xp_1 = x1352_p_0, xp_0 = 0;
									x < x1352 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12168 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12169 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12170 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12171 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12180 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12181 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
												c < c1014 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12168);
												mem_vec_12168 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12169);
												mem_vec_12169 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12170);
												mem_vec_12170 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12171);
												mem_vec_12171 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12172);
												mem_vec_12172 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12173);
												mem_vec_12173 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12174);
												mem_vec_12174 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12175);
												mem_vec_12175 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12176);
												mem_vec_12176 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12177);
												mem_vec_12177 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12178);
												mem_vec_12178 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12179);
												mem_vec_12179 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12180);
												mem_vec_12180 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12181);
												mem_vec_12181 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12182);
												mem_vec_12182 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12183);
												mem_vec_12183 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12175);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12176);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12177);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12178);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12179);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12180);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12181);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12182);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12183);
								}
							}
						}
					}
					for (y = y676 + 12, yp_0 = 0;
						y < y676 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x1352 = x1353, x1352_p_1 = x1353_p_0, x1352_p_0 = 0;
							x1352 < x1353 + 1;
							x1352 += 1, x1352_p_1 += 1, x1352_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1352, fp_2 = f1352_p_1, fp_1 = f1352_p_0, fp_0 = 0;
								f < f1352 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1352, xp_2 = x1352_p_1, xp_1 = x1352_p_0, xp_0 = 0;
									x < x1352 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12184 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12185 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12186 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12187 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12196 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12197 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
												c < c1014 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12184);
												mem_vec_12184 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12185);
												mem_vec_12185 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12186);
												mem_vec_12186 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12187);
												mem_vec_12187 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12188);
												mem_vec_12188 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12189);
												mem_vec_12189 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12190);
												mem_vec_12190 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12191);
												mem_vec_12191 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12192);
												mem_vec_12192 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12193);
												mem_vec_12193 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12194);
												mem_vec_12194 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12195);
												mem_vec_12195 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12196);
												mem_vec_12196 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12197);
												mem_vec_12197 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12198);
												mem_vec_12198 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12199);
												mem_vec_12199 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12200);
												mem_vec_12200 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12201);
												mem_vec_12201 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12202);
												mem_vec_12202 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12203);
												mem_vec_12203 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12184);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12185);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12186);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12187);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12188);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12189);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12190);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12191);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12192);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12193);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12194);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12195);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12196);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12197);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12198);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12199);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12200);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12201);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12202);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12203);
								}
							}
						}
					}
			}
		}
	}
}


}