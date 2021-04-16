#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (8, y); T (2, f); T (68, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c108_p_0, cp_1, c108, f, fp_0, x, xp_0, x180_p_0, x181_p_0, x182_p_0, xp_1, x180_p_1, x181_p_1, xp_2, x180_p_2, xp_3, x180, x181, x182, y, yp_0, y144_p_0, y145_p_0, yp_1, y144_p_1, yp_2, y144, y145;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y146 = 0;
IND_TYPE x183 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c109 = 0;
IND_TYPE f72 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y145 = y146, y145_p_0 = 0;
		y145 < y146 + 96;
		y145 += 32, y145_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x182 = x183, x182_p_0 = 0;
			x182 < x183 + 136;
			x182 += 136, x182_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y144 = y145, y144_p_1 = y145_p_0, y144_p_0 = 0;
				y144 < y145 + 32;
				y144 += 32, y144_p_1 += 32, y144_p_0 += 32){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x181 = x182, x181_p_1 = x182_p_0, x181_p_0 = 0;
					x181 < x182 + 136;
					x181 += 2, x181_p_1 += 2, x181_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f72, fp_0 = 0;
						f < f72 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y144, yp_2 = y144_p_1, yp_1 = y144_p_0, yp_0 = 0;
							y < y144 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x180 = x181, x180_p_2 = x181_p_1, x180_p_1 = x181_p_0, x180_p_0 = 0;
								x180 < x181 + 2;
								x180 += 1, x180_p_2 += 1, x180_p_1 += 1, x180_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c108 = c109, c108_p_0 = 0;
									c108 < c109 + 128;
									c108 += 64, c108_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x180, xp_3 = x180_p_2, xp_2 = x180_p_1, xp_1 = x180_p_0, xp_0 = 0;
										x < x180 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_896 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_897 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_898 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_899 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_904 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_905 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_906 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_907 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c108, cp_1 = c108_p_0, cp_0 = 0;
													c < c108 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_896);
													mem_vec_896 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_897);
													mem_vec_897 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_898);
													mem_vec_898 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_899);
													mem_vec_899 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_900);
													mem_vec_900 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_901);
													mem_vec_901 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_902);
													mem_vec_902 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_903);
													mem_vec_903 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_904);
													mem_vec_904 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_905);
													mem_vec_905 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_906);
													mem_vec_906 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_907);
													mem_vec_907 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_908);
													mem_vec_908 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_909);
													mem_vec_909 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_910);
													mem_vec_910 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_911);
													mem_vec_911 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_896);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_897);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_898);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_899);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_900);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_901);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_902);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_903);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_911);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y145 = y146 + 96, y145_p_0 = 0;
		y145 < y146 + 96 + 40;
		y145 += 40, y145_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x182 = x183, x182_p_0 = 0;
			x182 < x183 + 136;
			x182 += 136, x182_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y144 = y145, y144_p_1 = y145_p_0, y144_p_0 = 0;
				y144 < y145 + 40;
				y144 += 40, y144_p_1 += 40, y144_p_0 += 40){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x181 = x182, x181_p_1 = x182_p_0, x181_p_0 = 0;
					x181 < x182 + 136;
					x181 += 2, x181_p_1 += 2, x181_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f72, fp_0 = 0;
						f < f72 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y144, yp_2 = y144_p_1, yp_1 = y144_p_0, yp_0 = 0;
							y < y144 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x180 = x181, x180_p_2 = x181_p_1, x180_p_1 = x181_p_0, x180_p_0 = 0;
								x180 < x181 + 2;
								x180 += 1, x180_p_2 += 1, x180_p_1 += 1, x180_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 2) (128 / 64)
								for (c108 = c109, c108_p_0 = 0;
									c108 < c109 + 128;
									c108 += 64, c108_p_0 += 64){
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (x, 1) (1 / 1)
									for (x = x180, xp_3 = x180_p_2, xp_2 = x180_p_1, xp_1 = x180_p_0, xp_0 = 0;
										x < x180 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_912 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_913 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_914 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_915 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c108, cp_1 = c108_p_0, cp_0 = 0;
													c < c108 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_912);
													mem_vec_912 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_913);
													mem_vec_913 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_914);
													mem_vec_914 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_915);
													mem_vec_915 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_916);
													mem_vec_916 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_917);
													mem_vec_917 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_918);
													mem_vec_918 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_919);
													mem_vec_919 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_920);
													mem_vec_920 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_921);
													mem_vec_921 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_922);
													mem_vec_922 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_923);
													mem_vec_923 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_924);
													mem_vec_924 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_925);
													mem_vec_925 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_926);
													mem_vec_926 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_927);
													mem_vec_927 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_928);
													mem_vec_928 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_929);
													mem_vec_929 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_930);
													mem_vec_930 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_931);
													mem_vec_931 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_923);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_927);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_928);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_929);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_930);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_931);
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