#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (2, y); T (2, f); T (2, x); T (4, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, x, xp_0, x460_p_0, x461_p_0, x462_p_0, xp_1, x460_p_1, x461_p_1, xp_2, x460_p_2, xp_3, x460, x461, x462, y, yp_0, y368_p_0, y369_p_0, yp_1, y368_p_1, yp_2, y368, y369;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y370 = 0;
IND_TYPE x463 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c277 = 0;
IND_TYPE f184 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,mem_vec_2940 ,mem_vec_2941 ,mem_vec_2942 ,mem_vec_2943 ,mem_vec_2944 ,mem_vec_2945 ,mem_vec_2946 ,mem_vec_2947 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y369 = y370, y369_p_0 = 0;
		y369 < y370 + 96;
		y369 += 32, y369_p_0 += 32){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x462 = x463, x462_p_0 = 0;
			x462 < x463 + 136;
			x462 += 2, x462_p_0 += 2){
			// y = 4 * (2 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y368 = y369, y368_p_1 = y369_p_0, y368_p_0 = 0;
				y368 < y369 + 32;
				y368 += 8, y368_p_1 += 8, y368_p_0 += 8){
				// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x461 = x462, x461_p_1 = x462_p_0, x461_p_0 = 0;
					x461 < x462 + 2;
					x461 += 1, x461_p_1 += 1, x461_p_0 += 1){
					// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f184, fp_0 = 0;
						f < f184 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y368, yp_2 = y368_p_1, yp_1 = y368_p_0, yp_0 = 0;
							y < y368 + 8;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x460 = x461, x460_p_2 = x461_p_1, x460_p_1 = x461_p_0, x460_p_0 = 0;
								x460 < x461 + 1;
								x460 += 1, x460_p_2 += 1, x460_p_1 += 1, x460_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c276 = c277, c276_p_0 = 0;
									c276 < c277 + 128;
									c276 += 128, c276_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x460, xp_3 = x460_p_2, xp_2 = x460_p_1, xp_1 = x460_p_0, xp_0 = 0;
										x < x460 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2912 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2913 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2914 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2915 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;
													c < c276 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2912);
													mem_vec_2912 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2913);
													mem_vec_2913 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2914);
													mem_vec_2914 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2915);
													mem_vec_2915 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2916);
													mem_vec_2916 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2917);
													mem_vec_2917 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2918);
													mem_vec_2918 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2919);
													mem_vec_2919 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2920);
													mem_vec_2920 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2921);
													mem_vec_2921 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2922);
													mem_vec_2922 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2923);
													mem_vec_2923 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2924);
													mem_vec_2924 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2925);
													mem_vec_2925 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2926);
													mem_vec_2926 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2927);
													mem_vec_2927 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2923);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2927);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y369 = y370 + 96, y369_p_0 = 0;
		y369 < y370 + 96 + 40;
		y369 += 40, y369_p_0 += 40){
		// y = 4 * (2 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x462 = x463, x462_p_0 = 0;
			x462 < x463 + 136;
			x462 += 2, x462_p_0 += 2){
			// y = 4 * (2 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 4) (4 * (2 * ph_y) / 2 * ph_y)
			for (y368 = y369, y368_p_1 = y369_p_0, y368_p_0 = 0;
				y368 < y369 + 40;
				y368 += 10, y368_p_1 += 10, y368_p_0 += 10){
				// y = 2 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 2) (2 / 1)
				for (x461 = x462, x461_p_1 = x462_p_0, x461_p_0 = 0;
					x461 < x462 + 2;
					x461 += 1, x461_p_1 += 1, x461_p_0 += 1){
					// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f184, fp_0 = 0;
						f < f184 + 64;
						f += 32, fp_0 += 32){
						// y = 2 * ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (y, 2) (2 * ph_y / ph_y)
						for (y = y368, yp_2 = y368_p_1, yp_1 = y368_p_0, yp_0 = 0;
							y < y368 + 10;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (1 / 1)
							for (x460 = x461, x460_p_2 = x461_p_1, x460_p_1 = x461_p_0, x460_p_0 = 0;
								x460 < x461 + 1;
								x460 += 1, x460_p_2 += 1, x460_p_1 += 1, x460_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c276 = c277, c276_p_0 = 0;
									c276 < c277 + 128;
									c276 += 128, c276_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x460, xp_3 = x460_p_2, xp_2 = x460_p_1, xp_1 = x460_p_0, xp_0 = 0;
										x < x460 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2928 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2929 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2930 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2931 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_2932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_2936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2938 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2939 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_2940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_2944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;
													c < c276 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2928);
													mem_vec_2928 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2929);
													mem_vec_2929 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2930);
													mem_vec_2930 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_2931);
													mem_vec_2931 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_2932);
													mem_vec_2932 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_2933);
													mem_vec_2933 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_2934);
													mem_vec_2934 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_2935);
													mem_vec_2935 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2936);
													mem_vec_2936 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2937);
													mem_vec_2937 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_2938);
													mem_vec_2938 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_2939);
													mem_vec_2939 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_2940);
													mem_vec_2940 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_2941);
													mem_vec_2941 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_2942);
													mem_vec_2942 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_2943);
													mem_vec_2943 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_2944);
													mem_vec_2944 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_2945);
													mem_vec_2945 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_2946);
													mem_vec_2946 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_2947);
													mem_vec_2947 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2928);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2929);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2930);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_2931);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2932);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2933);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2934);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_2935);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2936);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2937);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2938);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_2939);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2940);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2941);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2942);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_2943);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_2947);
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