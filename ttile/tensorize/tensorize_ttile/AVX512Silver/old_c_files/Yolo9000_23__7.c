#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (1024, c); Hoist_vars [c]; T (17, x);
  T (589, f); T (1, x); T (1, y); T (1, c); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (3, f)]
*/
IND_TYPE c, cp_0, c531_p_0, cp_1, c531, f, fp_0, f708_p_0, f709_p_0, fp_1, f708_p_1, fp_2, f708, f709, x, xp_0, x708_p_0, x709_p_0, xp_1, x708_p_1, xp_2, x708, x709, y, yp_0, y531_p_0, yp_1, y531;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y532 = 0;
IND_TYPE x710 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c532 = 0;
IND_TYPE f710 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_3009 ,mem_vec_3010 ,mem_vec_3011 ,mem_vec_3012 ,mem_vec_3013 ,mem_vec_3014 ,mem_vec_3015 ,mem_vec_3016 ,mem_vec_3017 ,mem_vec_3018 ,mem_vec_3019 ,mem_vec_3020 ,mem_vec_3021 ,mem_vec_3022 ,mem_vec_3023 ,mem_vec_3024 ,mem_vec_3025 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 3) (28272 / 9424)
for (f709 = f710, f709_p_0 = 0;
	f709 < f710 + 28272;
	f709 += 9424, f709_p_0 += 9424){
		for (y531 = y532, y531_p_0 = 0;
			y531 < y532 + 8;
			y531 += 8, y531_p_0 += 8){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
			// T (x, 1) (17 / 17)
			for (x709 = x710, x709_p_0 = 0;
				x709 < x710 + 17;
				x709 += 17, x709_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
				// T (f, 1) (9424 / 9424)
				for (f708 = f709, f708_p_1 = f709_p_0, f708_p_0 = 0;
					f708 < f709 + 9424;
					f708 += 9424, f708_p_1 += 9424, f708_p_0 += 9424){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
					// T (c, 1) (1024 / 1024)
					for (c531 = c532, c531_p_0 = 0;
						c531 < c532 + 1024;
						c531 += 1024, c531_p_0 += 1024){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
						// T (y, 1) (ph_y / ph_y)
						for (y = y531, yp_1 = y531_p_0, yp_0 = 0;
							y < y531 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
							// T (x, 1) (17 / 17)
							for (x708 = x709, x708_p_1 = x709_p_0, x708_p_0 = 0;
								x708 < x709 + 17;
								x708 += 17, x708_p_1 += 17, x708_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
								// T (f, 589) (9424 / 16)
								for (f = f708, fp_2 = f708_p_1, fp_1 = f708_p_0, fp_0 = 0;
									f < f708 + 9424;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
									// T (x, 17) (17 / 1)
									for (x = x708, xp_2 = x708_p_1, xp_1 = x708_p_0, xp_0 = 0;
										x < x708 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c531, cp_1 = c531_p_0, cp_0 = 0;
													c < c531 + 1024;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3009);
													mem_vec_3009 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3010);
													mem_vec_3010 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3011);
													mem_vec_3011 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3012);
													mem_vec_3012 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3013);
													mem_vec_3013 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3014);
													mem_vec_3014 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3015);
													mem_vec_3015 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_3016);
													mem_vec_3016 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3009);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3010);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3011);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3012);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3013);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3014);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3015);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3016);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y531 = y532 + 8, y531_p_0 = 0;
			y531 < y532 + 8 + 9;
			y531 += 9, y531_p_0 += 9){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
			// T (x, 1) (17 / 17)
			for (x709 = x710, x709_p_0 = 0;
				x709 < x710 + 17;
				x709 += 17, x709_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
				// T (f, 1) (9424 / 9424)
				for (f708 = f709, f708_p_1 = f709_p_0, f708_p_0 = 0;
					f708 < f709 + 9424;
					f708 += 9424, f708_p_1 += 9424, f708_p_0 += 9424){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
					// T (c, 1) (1024 / 1024)
					for (c531 = c532, c531_p_0 = 0;
						c531 < c532 + 1024;
						c531 += 1024, c531_p_0 += 1024){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
						// T (y, 1) (ph_y / ph_y)
						for (y = y531, yp_1 = y531_p_0, yp_0 = 0;
							y < y531 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
							// T (x, 1) (17 / 17)
							for (x708 = x709, x708_p_1 = x709_p_0, x708_p_0 = 0;
								x708 < x709 + 17;
								x708 += 17, x708_p_1 += 17, x708_p_0 += 17){
								// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 9424
								// T (f, 589) (9424 / 16)
								for (f = f708, fp_2 = f708_p_1, fp_1 = f708_p_0, fp_0 = 0;
									f < f708 + 9424;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 16
									// T (x, 17) (17 / 1)
									for (x = x708, xp_2 = x708_p_1, xp_1 = x708_p_0, xp_0 = 0;
										x < x708 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3017 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 16
												// T (c, 1024) (1024 / 1)
												for (c = c531, cp_1 = c531_p_0, cp_0 = 0;
													c < c531 + 1024;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3017);
													mem_vec_3017 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3018);
													mem_vec_3018 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3019);
													mem_vec_3019 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3020);
													mem_vec_3020 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3021);
													mem_vec_3021 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3022);
													mem_vec_3022 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3023);
													mem_vec_3023 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_3024);
													mem_vec_3024 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3025);
													mem_vec_3025 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3017);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3018);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3019);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3020);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3021);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3022);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3023);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3024);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3025);
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