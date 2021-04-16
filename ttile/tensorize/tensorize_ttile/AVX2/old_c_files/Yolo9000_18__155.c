#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (16, c); T (4, f); T (4, f)]
*/
IND_TYPE c, cp_0, c516_p_0, cp_1, c516, f, fp_0, f548_p_0, f549_p_0, fp_1, f548_p_1, fp_2, f548, f549, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y334 = 0;
IND_TYPE x304 = 0;
IND_TYPE h208 = 0;
IND_TYPE w270 = 0;
IND_TYPE c517 = 0;
IND_TYPE f550 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_6024 ,mem_vec_6025 ,mem_vec_6026 ,mem_vec_6027 ,mem_vec_6028 ,mem_vec_6029 ,mem_vec_6030 ,mem_vec_6031 ,mem_vec_6032 ,mem_vec_6033 ,mem_vec_6034 ,mem_vec_6035 ,mem_vec_6036 ,mem_vec_6037 ,mem_vec_6038 ,mem_vec_6039 ,mem_vec_6040 ,mem_vec_6041 ,mem_vec_6042 ,mem_vec_6043 ,mem_vec_6044 ,mem_vec_6045 ,mem_vec_6046 ,mem_vec_6047 ,mem_vec_6048 ,mem_vec_6049 ,mem_vec_6050 ,mem_vec_6051 ,mem_vec_6052 ,mem_vec_6053 ,mem_vec_6054 ,mem_vec_6055 ,mem_vec_6056 ,mem_vec_6057 ,mem_vec_6058 ,mem_vec_6059 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f549 = f550, f549_p_0 = 0;
	f549 < f550 + 1024;
	f549 += 256, f549_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (f, 4) (256 / 64)
	for (f548 = f549, f548_p_1 = f549_p_0, f548_p_0 = 0;
		f548 < f549 + 256;
		f548 += 64, f548_p_1 += 64, f548_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 64
		// T (c, 16) (512 / 32)
		for (c516 = c517, c516_p_0 = 0;
			c516 < c517 + 512;
			c516 += 32, c516_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 64
			// T (f, 2) (64 / 32)
			for (f = f548, fp_2 = f548_p_1, fp_1 = f548_p_0, fp_0 = 0;
				f < f548 + 64;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y334, yp_0 = 0;
						y < y334 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x304, xp_0 = 0;
							x < x304 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h208, hp_0 = 0;
								h < h208 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w270, wp_0 = 0;
									w < w270 + 3;
									w += 1, wp_0 += 1){
											mem_vec_6024 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6025 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6026 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6027 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6032 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6033 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6034 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6035 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
												c < c516 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6024);
												mem_vec_6024 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6025);
												mem_vec_6025 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6026);
												mem_vec_6026 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6027);
												mem_vec_6027 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6028);
												mem_vec_6028 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6029);
												mem_vec_6029 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6030);
												mem_vec_6030 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6031);
												mem_vec_6031 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6032);
												mem_vec_6032 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6033);
												mem_vec_6033 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6034);
												mem_vec_6034 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6035);
												mem_vec_6035 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6036);
												mem_vec_6036 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6037);
												mem_vec_6037 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6038);
												mem_vec_6038 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6039);
												mem_vec_6039 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6024);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6025);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6026);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6027);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6028);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6029);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6030);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6031);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6032);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6033);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6034);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6035);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6036);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6037);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6038);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6039);
								}
							}
						}
					}
					for (y = y334 + 12, yp_0 = 0;
						y < y334 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x304, xp_0 = 0;
							x < x304 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h208, hp_0 = 0;
								h < h208 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w270, wp_0 = 0;
									w < w270 + 3;
									w += 1, wp_0 += 1){
											mem_vec_6040 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6041 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6042 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6043 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_6044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_6048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_6052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_6056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
												c < c516 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6040);
												mem_vec_6040 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6041);
												mem_vec_6041 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6042);
												mem_vec_6042 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6043);
												mem_vec_6043 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6044);
												mem_vec_6044 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6045);
												mem_vec_6045 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6046);
												mem_vec_6046 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6047);
												mem_vec_6047 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6048);
												mem_vec_6048 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6049);
												mem_vec_6049 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6050);
												mem_vec_6050 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6051);
												mem_vec_6051 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6052);
												mem_vec_6052 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6053);
												mem_vec_6053 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6054);
												mem_vec_6054 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6055);
												mem_vec_6055 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6056);
												mem_vec_6056 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6057);
												mem_vec_6057 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6058);
												mem_vec_6058 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6059);
												mem_vec_6059 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6040);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6041);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6042);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6043);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6044);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6045);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6046);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6047);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6048);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6049);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6050);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6051);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6052);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6053);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6054);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6055);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6056);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6057);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6058);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6059);
								}
							}
						}
					}
			}
		}
	}
}


}