#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (2, f); T (4, f)]
*/
IND_TYPE c, cp_0, c222_p_0, cp_1, c222, f, fp_0, f296_p_0, f297_p_0, fp_1, f296_p_1, fp_2, f296, f297, h, hp_0, w, wp_0, x, xp_0, x222_p_0, xp_1, x222, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y148 = 0;
IND_TYPE x223 = 0;
IND_TYPE h148 = 0;
IND_TYPE w134 = 0;
IND_TYPE c223 = 0;
IND_TYPE f298 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,mem_vec_2940 ,mem_vec_2941 ,mem_vec_2942 ,mem_vec_2943 ,mem_vec_2944 ,mem_vec_2945 ,mem_vec_2946 ,mem_vec_2947 ,mem_vec_2948 ,mem_vec_2949 ,mem_vec_2950 ,mem_vec_2951 ,mem_vec_2952 ,mem_vec_2953 ,mem_vec_2954 ,mem_vec_2955 ,mem_vec_2956 ,mem_vec_2957 ,mem_vec_2958 ,mem_vec_2959 ,mem_vec_2960 ,mem_vec_2961 ,mem_vec_2962 ,mem_vec_2963 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f297 = f298, f297_p_0 = 0;
	f297 < f298 + 256;
	f297 += 64, f297_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 2) (64 / 32)
	for (f296 = f297, f296_p_1 = f297_p_0, f296_p_0 = 0;
		f296 < f297 + 64;
		f296 += 32, f296_p_1 += 32, f296_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x222 = x223, x222_p_0 = 0;
			x222 < x223 + 68;
			x222 += 17, x222_p_0 += 17){
				for (y = y148, yp_0 = 0;
					y < y148 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f296, fp_2 = f296_p_1, fp_1 = f296_p_0, fp_0 = 0;
						f < f296 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c222 = c223, c222_p_0 = 0;
							c222 < c223 + 128;
							c222 += 16, c222_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w134, wp_0 = 0;
								w < w134 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x222, xp_1 = x222_p_0, xp_0 = 0;
									x < x222 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h148, hp_0 = 0;
										h < h148 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2924 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2925 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c222, cp_1 = c222_p_0, cp_0 = 0;
													c < c222 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2924);
													mem_vec_2924 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2925);
													mem_vec_2925 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2926);
													mem_vec_2926 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2927);
													mem_vec_2927 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2928);
													mem_vec_2928 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2929);
													mem_vec_2929 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2930);
													mem_vec_2930 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2931);
													mem_vec_2931 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2932);
													mem_vec_2932 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2933);
													mem_vec_2933 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2934);
													mem_vec_2934 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2935);
													mem_vec_2935 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2936);
													mem_vec_2936 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2937);
													mem_vec_2937 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2938);
													mem_vec_2938 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2939);
													mem_vec_2939 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2924);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2925);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2926);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2927);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2928);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2929);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2930);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2931);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2932);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2933);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2934);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2935);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2936);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2937);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2938);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2939);
									}
								}
							}
						}
					}
				}
				for (y = y148 + 8, yp_0 = 0;
					y < y148 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f296, fp_2 = f296_p_1, fp_1 = f296_p_0, fp_0 = 0;
						f < f296 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c222 = c223, c222_p_0 = 0;
							c222 < c223 + 128;
							c222 += 16, c222_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w134, wp_0 = 0;
								w < w134 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x222, xp_1 = x222_p_0, xp_0 = 0;
									x < x222 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h148, hp_0 = 0;
										h < h148 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2940 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2941 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_2956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_2957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_2958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_2959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_2960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_2961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_2962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_2963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c222, cp_1 = c222_p_0, cp_0 = 0;
													c < c222 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2940);
													mem_vec_2940 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2941);
													mem_vec_2941 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2942);
													mem_vec_2942 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2943);
													mem_vec_2943 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2944);
													mem_vec_2944 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2945);
													mem_vec_2945 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2946);
													mem_vec_2946 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2947);
													mem_vec_2947 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2948);
													mem_vec_2948 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2949);
													mem_vec_2949 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2950);
													mem_vec_2950 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2951);
													mem_vec_2951 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2952);
													mem_vec_2952 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2953);
													mem_vec_2953 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2954);
													mem_vec_2954 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2955);
													mem_vec_2955 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2956);
													mem_vec_2956 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2957);
													mem_vec_2957 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2958);
													mem_vec_2958 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2959);
													mem_vec_2959 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2960);
													mem_vec_2960 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2961);
													mem_vec_2961 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2962);
													mem_vec_2962 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2963);
													mem_vec_2963 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2940);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2941);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2942);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2943);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2944);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2945);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2946);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2947);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2948);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2949);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2950);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2951);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2952);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2953);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2954);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2955);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2956);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2957);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2958);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2959);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2960);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2961);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2962);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2963);
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