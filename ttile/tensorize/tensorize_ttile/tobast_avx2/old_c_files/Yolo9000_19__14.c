#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (1, f); T (16, c); T (17, x); T (8, f)]
*/
IND_TYPE c, cp_0, c1008_p_0, cp_1, c1008, f, fp_0, f1344_p_0, f1345_p_0, fp_1, f1344_p_1, fp_2, f1344, f1345, x, xp_0, x1344_p_0, x1345_p_0, xp_1, x1344_p_1, xp_2, x1344, x1345, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y672 = 0;
IND_TYPE x1346 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1009 = 0;
IND_TYPE f1346 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_12096 ,mem_vec_12097 ,mem_vec_12098 ,mem_vec_12099 ,mem_vec_12100 ,mem_vec_12101 ,mem_vec_12102 ,mem_vec_12103 ,mem_vec_12104 ,mem_vec_12105 ,mem_vec_12106 ,mem_vec_12107 ,mem_vec_12108 ,mem_vec_12109 ,mem_vec_12110 ,mem_vec_12111 ,mem_vec_12112 ,mem_vec_12113 ,mem_vec_12114 ,mem_vec_12115 ,mem_vec_12116 ,mem_vec_12117 ,mem_vec_12118 ,mem_vec_12119 ,mem_vec_12120 ,mem_vec_12121 ,mem_vec_12122 ,mem_vec_12123 ,mem_vec_12124 ,mem_vec_12125 ,mem_vec_12126 ,mem_vec_12127 ,mem_vec_12128 ,mem_vec_12129 ,mem_vec_12130 ,mem_vec_12131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 8) (512 / 64)
for (f1345 = f1346, f1345_p_0 = 0;
	f1345 < f1346 + 512;
	f1345 += 64, f1345_p_0 += 64){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 64
	// T (x, 17) (17 / 1)
	for (x1345 = x1346, x1345_p_0 = 0;
		x1345 < x1346 + 17;
		x1345 += 1, x1345_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 64
		// T (c, 16) (1024 / 64)
		for (c1008 = c1009, c1008_p_0 = 0;
			c1008 < c1009 + 1024;
			c1008 += 64, c1008_p_0 += 64){
			// y = 17, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (f, 1) (64 / 64)
			for (f1344 = f1345, f1344_p_1 = f1345_p_0, f1344_p_0 = 0;
				f1344 < f1345 + 64;
				f1344 += 64, f1344_p_1 += 64, f1344_p_0 += 64){
					for (y = y672, yp_0 = 0;
						y < y672 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
						// T (x, 1) (1 / 1)
						for (x1344 = x1345, x1344_p_1 = x1345_p_0, x1344_p_0 = 0;
							x1344 < x1345 + 1;
							x1344 += 1, x1344_p_1 += 1, x1344_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1344, fp_2 = f1344_p_1, fp_1 = f1344_p_0, fp_0 = 0;
								f < f1344 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1344, xp_2 = x1344_p_1, xp_1 = x1344_p_0, xp_0 = 0;
									x < x1344 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12096 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12097 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12098 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12099 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1008, cp_1 = c1008_p_0, cp_0 = 0;
												c < c1008 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12096);
												mem_vec_12096 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12097);
												mem_vec_12097 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12098);
												mem_vec_12098 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12099);
												mem_vec_12099 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12100);
												mem_vec_12100 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12101);
												mem_vec_12101 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12102);
												mem_vec_12102 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12103);
												mem_vec_12103 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12104);
												mem_vec_12104 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12105);
												mem_vec_12105 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12106);
												mem_vec_12106 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12107);
												mem_vec_12107 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12108);
												mem_vec_12108 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12109);
												mem_vec_12109 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12110);
												mem_vec_12110 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12111);
												mem_vec_12111 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12096);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12097);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12098);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12099);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12100);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12101);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12102);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12103);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12104);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12105);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12106);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12107);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12108);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12109);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12110);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12111);
								}
							}
						}
					}
					for (y = y672 + 12, yp_0 = 0;
						y < y672 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
						// T (x, 1) (1 / 1)
						for (x1344 = x1345, x1344_p_1 = x1345_p_0, x1344_p_0 = 0;
							x1344 < x1345 + 1;
							x1344 += 1, x1344_p_1 += 1, x1344_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1344, fp_2 = f1344_p_1, fp_1 = f1344_p_0, fp_0 = 0;
								f < f1344 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1344, xp_2 = x1344_p_1, xp_1 = x1344_p_0, xp_0 = 0;
									x < x1344 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_12112 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_12113 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_12114 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_12115 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_12116 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_12117 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_12118 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_12119 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_12120 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_12121 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_12122 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_12123 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_12124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_12125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_12126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_12127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_12128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_12129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_12130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_12131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c1008, cp_1 = c1008_p_0, cp_0 = 0;
												c < c1008 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12112);
												mem_vec_12112 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12113);
												mem_vec_12113 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12114);
												mem_vec_12114 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12115);
												mem_vec_12115 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12116);
												mem_vec_12116 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12117);
												mem_vec_12117 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12118);
												mem_vec_12118 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12119);
												mem_vec_12119 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12120);
												mem_vec_12120 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12121);
												mem_vec_12121 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12122);
												mem_vec_12122 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12123);
												mem_vec_12123 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12124);
												mem_vec_12124 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12125);
												mem_vec_12125 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12126);
												mem_vec_12126 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12127);
												mem_vec_12127 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12128);
												mem_vec_12128 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12129);
												mem_vec_12129 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12130);
												mem_vec_12130 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12131);
												mem_vec_12131 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12112);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12113);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12114);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12115);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12116);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12117);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12118);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12119);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12120);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12121);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12122);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12123);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12124);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12125);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12126);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12127);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12128);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12129);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12130);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12131);
								}
							}
						}
					}
			}
		}
	}
}


}