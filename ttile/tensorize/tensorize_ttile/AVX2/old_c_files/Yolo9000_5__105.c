#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (2, x); T (8, y); T (2, f); T (68, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c111_p_0, cp_1, c111, f, fp_0, x, xp_0, x185_p_0, x186_p_0, x187_p_0, xp_1, x185_p_1, x186_p_1, xp_2, x185_p_2, xp_3, x185, x186, x187, y, yp_0, y148_p_0, y149_p_0, yp_1, y148_p_1, yp_2, y148, y149;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y150 = 0;
IND_TYPE x188 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c112 = 0;
IND_TYPE f74 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y149 = y150, y149_p_0 = 0;
		y149 < y150 + 96;
		y149 += 32, y149_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x187 = x188, x187_p_0 = 0;
			x187 < x188 + 136;
			x187 += 136, x187_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y148 = y149, y148_p_1 = y149_p_0, y148_p_0 = 0;
				y148 < y149 + 32;
				y148 += 32, y148_p_1 += 32, y148_p_0 += 32){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x186 = x187, x186_p_1 = x187_p_0, x186_p_0 = 0;
					x186 < x187 + 136;
					x186 += 2, x186_p_1 += 2, x186_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f74, fp_0 = 0;
						f < f74 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y148, yp_2 = y148_p_1, yp_1 = y148_p_0, yp_0 = 0;
							y < y148 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x185 = x186, x185_p_2 = x186_p_1, x185_p_1 = x186_p_0, x185_p_0 = 0;
								x185 < x186 + 2;
								x185 += 1, x185_p_2 += 1, x185_p_1 += 1, x185_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c111 = c112, c111_p_0 = 0;
									c111 < c112 + 128;
									c111 += 32, c111_p_0 += 32){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x185, xp_3 = x185_p_2, xp_2 = x185_p_1, xp_1 = x185_p_0, xp_0 = 0;
										x < x185 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_932 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_933 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_934 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_935 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_938 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_939 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c111, cp_1 = c111_p_0, cp_0 = 0;
													c < c111 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_932);
													mem_vec_932 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_933);
													mem_vec_933 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_934);
													mem_vec_934 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_935);
													mem_vec_935 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_936);
													mem_vec_936 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_937);
													mem_vec_937 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_938);
													mem_vec_938 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_939);
													mem_vec_939 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_940);
													mem_vec_940 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_941);
													mem_vec_941 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_942);
													mem_vec_942 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_943);
													mem_vec_943 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_944);
													mem_vec_944 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_945);
													mem_vec_945 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_946);
													mem_vec_946 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_947);
													mem_vec_947 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_932);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_933);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_934);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_935);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_936);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_937);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_938);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_939);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_940);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_941);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_942);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_943);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_947);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y149 = y150 + 96, y149_p_0 = 0;
		y149 < y150 + 96 + 40;
		y149 += 40, y149_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x187 = x188, x187_p_0 = 0;
			x187 < x188 + 136;
			x187 += 136, x187_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y148 = y149, y148_p_1 = y149_p_0, y148_p_0 = 0;
				y148 < y149 + 40;
				y148 += 40, y148_p_1 += 40, y148_p_0 += 40){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x186 = x187, x186_p_1 = x187_p_0, x186_p_0 = 0;
					x186 < x187 + 136;
					x186 += 2, x186_p_1 += 2, x186_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f74, fp_0 = 0;
						f < f74 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y148, yp_2 = y148_p_1, yp_1 = y148_p_0, yp_0 = 0;
							y < y148 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x185 = x186, x185_p_2 = x186_p_1, x185_p_1 = x186_p_0, x185_p_0 = 0;
								x185 < x186 + 2;
								x185 += 1, x185_p_2 += 1, x185_p_1 += 1, x185_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c111 = c112, c111_p_0 = 0;
									c111 < c112 + 128;
									c111 += 32, c111_p_0 += 32){
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x185, xp_3 = x185_p_2, xp_2 = x185_p_1, xp_1 = x185_p_0, xp_0 = 0;
										x < x185 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_948 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_949 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_950 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_951 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c111, cp_1 = c111_p_0, cp_0 = 0;
													c < c111 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_948);
													mem_vec_948 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_949);
													mem_vec_949 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_950);
													mem_vec_950 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_951);
													mem_vec_951 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_952);
													mem_vec_952 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_953);
													mem_vec_953 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_954);
													mem_vec_954 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_955);
													mem_vec_955 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_956);
													mem_vec_956 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_957);
													mem_vec_957 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_958);
													mem_vec_958 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_959);
													mem_vec_959 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_960);
													mem_vec_960 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_961);
													mem_vec_961 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_962);
													mem_vec_962 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_963);
													mem_vec_963 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_964);
													mem_vec_964 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_965);
													mem_vec_965 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_966);
													mem_vec_966 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_967);
													mem_vec_967 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_948);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_949);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_950);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_951);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_952);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_953);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_954);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_955);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_956);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_957);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_958);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_959);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_960);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_961);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_962);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_963);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_964);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_965);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_966);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_967);
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