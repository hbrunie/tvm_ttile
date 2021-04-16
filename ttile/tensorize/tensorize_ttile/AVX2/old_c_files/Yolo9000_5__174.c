#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (1, y); T (2, f); T (2, x); T (8, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c288_p_0, cp_1, c288, f, fp_0, x, xp_0, x480_p_0, x481_p_0, x482_p_0, xp_1, x480_p_1, x481_p_1, xp_2, x480_p_2, xp_3, x480, x481, x482, y, yp_0, y384_p_0, y385_p_0, yp_1, y384_p_1, yp_2, y384, y385;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y386 = 0;
IND_TYPE x483 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c289 = 0;
IND_TYPE f192 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_3056 ,mem_vec_3057 ,mem_vec_3058 ,mem_vec_3059 ,mem_vec_3060 ,mem_vec_3061 ,mem_vec_3062 ,mem_vec_3063 ,mem_vec_3064 ,mem_vec_3065 ,mem_vec_3066 ,mem_vec_3067 ,mem_vec_3068 ,mem_vec_3069 ,mem_vec_3070 ,mem_vec_3071 ,mem_vec_3072 ,mem_vec_3073 ,mem_vec_3074 ,mem_vec_3075 ,mem_vec_3076 ,mem_vec_3077 ,mem_vec_3078 ,mem_vec_3079 ,mem_vec_3080 ,mem_vec_3081 ,mem_vec_3082 ,mem_vec_3083 ,mem_vec_3084 ,mem_vec_3085 ,mem_vec_3086 ,mem_vec_3087 ,mem_vec_3088 ,mem_vec_3089 ,mem_vec_3090 ,mem_vec_3091 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y385 = y386, y385_p_0 = 0;
		y385 < y386 + 96;
		y385 += 32, y385_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x482 = x483, x482_p_0 = 0;
			x482 < x483 + 136;
			x482 += 2, x482_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y384 = y385, y384_p_1 = y385_p_0, y384_p_0 = 0;
				y384 < y385 + 32;
				y384 += 4, y384_p_1 += 4, y384_p_0 += 4){
				// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x481 = x482, x481_p_1 = x482_p_0, x481_p_0 = 0;
					x481 < x482 + 2;
					x481 += 1, x481_p_1 += 1, x481_p_0 += 1){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f192, fp_0 = 0;
						f < f192 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 1) (ph_y / ph_y)
						for (y = y384, yp_2 = y384_p_1, yp_1 = y384_p_0, yp_0 = 0;
							y < y384 + 4;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x480 = x481, x480_p_2 = x481_p_1, x480_p_1 = x481_p_0, x480_p_0 = 0;
								x480 < x481 + 1;
								x480 += 1, x480_p_2 += 1, x480_p_1 += 1, x480_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c288 = c289, c288_p_0 = 0;
									c288 < c289 + 128;
									c288 += 64, c288_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x480, xp_3 = x480_p_2, xp_2 = x480_p_1, xp_1 = x480_p_0, xp_0 = 0;
										x < x480 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3056 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3057 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3058 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3059 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c288, cp_1 = c288_p_0, cp_0 = 0;
													c < c288 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3056);
													mem_vec_3056 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3057);
													mem_vec_3057 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3058);
													mem_vec_3058 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3059);
													mem_vec_3059 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3060);
													mem_vec_3060 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3061);
													mem_vec_3061 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3062);
													mem_vec_3062 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3063);
													mem_vec_3063 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3064);
													mem_vec_3064 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3065);
													mem_vec_3065 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3066);
													mem_vec_3066 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3067);
													mem_vec_3067 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3068);
													mem_vec_3068 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3069);
													mem_vec_3069 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3070);
													mem_vec_3070 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3071);
													mem_vec_3071 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3056);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3057);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3058);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3059);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3060);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3061);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3062);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3063);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3064);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3065);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3066);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3067);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3068);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3069);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3070);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3071);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y385 = y386 + 96, y385_p_0 = 0;
		y385 < y386 + 96 + 40;
		y385 += 40, y385_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x482 = x483, x482_p_0 = 0;
			x482 < x483 + 136;
			x482 += 2, x482_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 8) (8 * ph_y / ph_y)
			for (y384 = y385, y384_p_1 = y385_p_0, y384_p_0 = 0;
				y384 < y385 + 40;
				y384 += 5, y384_p_1 += 5, y384_p_0 += 5){
				// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x481 = x482, x481_p_1 = x482_p_0, x481_p_0 = 0;
					x481 < x482 + 2;
					x481 += 1, x481_p_1 += 1, x481_p_0 += 1){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f192, fp_0 = 0;
						f < f192 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 1) (ph_y / ph_y)
						for (y = y384, yp_2 = y384_p_1, yp_1 = y384_p_0, yp_0 = 0;
							y < y384 + 5;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x480 = x481, x480_p_2 = x481_p_1, x480_p_1 = x481_p_0, x480_p_0 = 0;
								x480 < x481 + 1;
								x480 += 1, x480_p_2 += 1, x480_p_1 += 1, x480_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c288 = c289, c288_p_0 = 0;
									c288 < c289 + 128;
									c288 += 64, c288_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x480, xp_3 = x480_p_2, xp_2 = x480_p_1, xp_1 = x480_p_0, xp_0 = 0;
										x < x480 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3072 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3073 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3074 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3075 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_3076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_3080 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3081 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3082 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3083 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_3084 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3085 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3086 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3087 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_3088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c288, cp_1 = c288_p_0, cp_0 = 0;
													c < c288 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3072);
													mem_vec_3072 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3073);
													mem_vec_3073 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3074);
													mem_vec_3074 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3075);
													mem_vec_3075 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3076);
													mem_vec_3076 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3077);
													mem_vec_3077 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3078);
													mem_vec_3078 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3079);
													mem_vec_3079 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3080);
													mem_vec_3080 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3081);
													mem_vec_3081 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3082);
													mem_vec_3082 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3083);
													mem_vec_3083 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3084);
													mem_vec_3084 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3085);
													mem_vec_3085 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3086);
													mem_vec_3086 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3087);
													mem_vec_3087 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3088);
													mem_vec_3088 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3089);
													mem_vec_3089 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3090);
													mem_vec_3090 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3091);
													mem_vec_3091 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3072);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3073);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3074);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3075);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3076);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3077);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3078);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3079);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3080);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3081);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3082);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3083);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3084);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3085);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3086);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3087);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3088);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3089);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3090);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3091);
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