#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (4, f);
  T (128, c); T (2, f)]
*/
IND_TYPE c, cp_0, c408_p_0, cp_1, c408, f, fp_0, f544_p_0, f545_p_0, fp_1, f544_p_1, fp_2, f544, f545, h, hp_0, w, wp_0, x, xp_0, x408_p_0, xp_1, x408, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y272 = 0;
IND_TYPE x409 = 0;
IND_TYPE h226 = 0;
IND_TYPE w208 = 0;
IND_TYPE c409 = 0;
IND_TYPE f546 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4016 ,mem_vec_4017 ,mem_vec_4018 ,mem_vec_4019 ,mem_vec_4020 ,mem_vec_4021 ,mem_vec_4022 ,mem_vec_4023 ,mem_vec_4024 ,mem_vec_4025 ,mem_vec_4026 ,mem_vec_4027 ,mem_vec_4028 ,mem_vec_4029 ,mem_vec_4030 ,mem_vec_4031 ,mem_vec_4032 ,mem_vec_4033 ,mem_vec_4034 ,mem_vec_4035 ,mem_vec_4036 ,mem_vec_4037 ,mem_vec_4038 ,mem_vec_4039 ,mem_vec_4040 ,mem_vec_4041 ,mem_vec_4042 ,mem_vec_4043 ,mem_vec_4044 ,mem_vec_4045 ,mem_vec_4046 ,mem_vec_4047 ,mem_vec_4048 ,mem_vec_4049 ,mem_vec_4050 ,mem_vec_4051 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f545 = f546, f545_p_0 = 0;
	f545 < f546 + 256;
	f545 += 128, f545_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 128
	// T (c, 128) (128 / 1)
	for (c408 = c409, c408_p_0 = 0;
		c408 < c409 + 128;
		c408 += 1, c408_p_0 += 1){
		// y = 14, x = 14, h = 3, w = 3, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f544 = f545, f544_p_1 = f545_p_0, f544_p_0 = 0;
			f544 < f545 + 128;
			f544 += 32, f544_p_1 += 32, f544_p_0 += 32){
				for (y = y272, yp_0 = 0;
					y < y272 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (14 / 14)
					for (x408 = x409, x408_p_0 = 0;
						x408 < x409 + 14;
						x408 += 14, x408_p_0 += 14){
						// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f544, fp_2 = f544_p_1, fp_1 = f544_p_0, fp_0 = 0;
							f < f544 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h226, hp_0 = 0;
								h < h226 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w208, wp_0 = 0;
									w < w208 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 1, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x408, xp_1 = x408_p_0, xp_0 = 0;
										x < x408 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4016 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4017 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4018 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4019 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4024 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4025 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4026 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4027 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c408, cp_1 = c408_p_0, cp_0 = 0;
													c < c408 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4016);
													mem_vec_4016 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4017);
													mem_vec_4017 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4018);
													mem_vec_4018 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4019);
													mem_vec_4019 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4020);
													mem_vec_4020 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4021);
													mem_vec_4021 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4022);
													mem_vec_4022 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4023);
													mem_vec_4023 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4024);
													mem_vec_4024 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4025);
													mem_vec_4025 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4026);
													mem_vec_4026 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4027);
													mem_vec_4027 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4028);
													mem_vec_4028 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4029);
													mem_vec_4029 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4030);
													mem_vec_4030 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4031);
													mem_vec_4031 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4016);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4017);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4018);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4019);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4020);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4021);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4022);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4023);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4024);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4025);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4026);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4027);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4028);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4029);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4030);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4031);
									}
								}
							}
						}
					}
				}
				for (y = y272 + 4, yp_0 = 0;
					y < y272 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (14 / 14)
					for (x408 = x409, x408_p_0 = 0;
						x408 < x409 + 14;
						x408 += 14, x408_p_0 += 14){
						// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f544, fp_2 = f544_p_1, fp_1 = f544_p_0, fp_0 = 0;
							f < f544 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h226, hp_0 = 0;
								h < h226 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w208, wp_0 = 0;
									w < w208 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 1, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x408, xp_1 = x408_p_0, xp_0 = 0;
										x < x408 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_4032 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4033 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4034 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4035 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4040 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4041 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4042 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4043 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_4048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_4050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c408, cp_1 = c408_p_0, cp_0 = 0;
													c < c408 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4032);
													mem_vec_4032 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4033);
													mem_vec_4033 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4034);
													mem_vec_4034 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4035);
													mem_vec_4035 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4036);
													mem_vec_4036 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4037);
													mem_vec_4037 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4038);
													mem_vec_4038 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4039);
													mem_vec_4039 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4040);
													mem_vec_4040 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4041);
													mem_vec_4041 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4042);
													mem_vec_4042 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4043);
													mem_vec_4043 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4044);
													mem_vec_4044 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4045);
													mem_vec_4045 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4046);
													mem_vec_4046 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4047);
													mem_vec_4047 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4048);
													mem_vec_4048 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4049);
													mem_vec_4049 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4050);
													mem_vec_4050 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4051);
													mem_vec_4051 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4032);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4033);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4034);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4035);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4036);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4037);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4038);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4039);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4040);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4041);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4042);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4043);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4044);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4045);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4046);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4047);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4048);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4049);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4050);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4051);
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