#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (1, f);
  T (1, x); T (1, y); T (16, c); T (589, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (3, f)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, f728_p_0, f729_p_0, fp_1, f728_p_1, fp_2, f728, f729, x, xp_0, x728_p_0, x729_p_0, xp_1, x728_p_1, xp_2, x728, x729, y, yp_0, y546_p_0, yp_1, y546;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y547 = 0;
IND_TYPE x730 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c547 = 0;
IND_TYPE f730 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_3094 ,mem_vec_3095 ,mem_vec_3096 ,mem_vec_3097 ,mem_vec_3098 ,mem_vec_3099 ,mem_vec_3100 ,mem_vec_3101 ,mem_vec_3102 ,mem_vec_3103 ,mem_vec_3104 ,mem_vec_3105 ,mem_vec_3106 ,mem_vec_3107 ,mem_vec_3108 ,mem_vec_3109 ,mem_vec_3110 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 3) (28272 / 9424)
for (f729 = f730, f729_p_0 = 0;
	f729 < f730 + 28272;
	f729 += 9424, f729_p_0 += 9424){
		for (y546 = y547, y546_p_0 = 0;
			y546 < y547 + 8;
			y546 += 8, y546_p_0 += 8){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
			// T (x, 1) (17 / 17)
			for (x729 = x730, x729_p_0 = 0;
				x729 < x730 + 17;
				x729 += 17, x729_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
				// T (f, 589) (9424 / 16)
				for (f728 = f729, f728_p_1 = f729_p_0, f728_p_0 = 0;
					f728 < f729 + 9424;
					f728 += 16, f728_p_1 += 16, f728_p_0 += 16){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
					// T (c, 16) (1024 / 64)
					for (c546 = c547, c546_p_0 = 0;
						c546 < c547 + 1024;
						c546 += 64, c546_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
						// T (y, 1) (ph_y / ph_y)
						for (y = y546, yp_1 = y546_p_0, yp_0 = 0;
							y < y546 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
							// T (x, 1) (17 / 17)
							for (x728 = x729, x728_p_1 = x729_p_0, x728_p_0 = 0;
								x728 < x729 + 17;
								x728 += 17, x728_p_1 += 17, x728_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
								// T (f, 1) (16 / 16)
								for (f = f728, fp_2 = f728_p_1, fp_1 = f728_p_0, fp_0 = 0;
									f < f728 + 16;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x728, xp_2 = x728_p_1, xp_1 = x728_p_0, xp_0 = 0;
										x < x728 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3094 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
													c < c546 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3094);
													mem_vec_3094 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3095);
													mem_vec_3095 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3096);
													mem_vec_3096 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3097);
													mem_vec_3097 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3098);
													mem_vec_3098 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3099);
													mem_vec_3099 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3100);
													mem_vec_3100 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_3101);
													mem_vec_3101 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3094);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3095);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3096);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3097);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3098);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3099);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3100);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3101);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y546 = y547 + 8, y546_p_0 = 0;
			y546 < y547 + 8 + 9;
			y546 += 9, y546_p_0 += 9){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
			// T (x, 1) (17 / 17)
			for (x729 = x730, x729_p_0 = 0;
				x729 < x730 + 17;
				x729 += 17, x729_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
				// T (f, 589) (9424 / 16)
				for (f728 = f729, f728_p_1 = f729_p_0, f728_p_0 = 0;
					f728 < f729 + 9424;
					f728 += 16, f728_p_1 += 16, f728_p_0 += 16){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
					// T (c, 16) (1024 / 64)
					for (c546 = c547, c546_p_0 = 0;
						c546 < c547 + 1024;
						c546 += 64, c546_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
						// T (y, 1) (ph_y / ph_y)
						for (y = y546, yp_1 = y546_p_0, yp_0 = 0;
							y < y546 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
							// T (x, 1) (17 / 17)
							for (x728 = x729, x728_p_1 = x729_p_0, x728_p_0 = 0;
								x728 < x729 + 17;
								x728 += 17, x728_p_1 += 17, x728_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
								// T (f, 1) (16 / 16)
								for (f = f728, fp_2 = f728_p_1, fp_1 = f728_p_0, fp_0 = 0;
									f < f728 + 16;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x728, xp_2 = x728_p_1, xp_1 = x728_p_0, xp_0 = 0;
										x < x728 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3102 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
													c < c546 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3102);
													mem_vec_3102 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3103);
													mem_vec_3103 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3104);
													mem_vec_3104 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3105);
													mem_vec_3105 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3106);
													mem_vec_3106 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3107);
													mem_vec_3107 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3108);
													mem_vec_3108 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_3109);
													mem_vec_3109 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3110);
													mem_vec_3110 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3102);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3103);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3104);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3105);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3106);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3107);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3108);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3109);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3110);
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