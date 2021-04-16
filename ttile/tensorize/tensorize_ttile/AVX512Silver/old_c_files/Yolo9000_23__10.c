#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; T (512, c); Hoist_vars [c]; T (1, x); T (3, f);
  T (17, x); T (1, y); T (2, c); T (19, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (31, f)]
*/
IND_TYPE c, cp_0, c120_p_0, cp_1, c120, f, fp_0, f160_p_0, f161_p_0, fp_1, f160_p_1, fp_2, f160, f161, x, xp_0, x160_p_0, x161_p_0, xp_1, x160_p_1, xp_2, x160, x161, y, yp_0, y120_p_0, yp_1, y120;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y121 = 0;
IND_TYPE x162 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c121 = 0;
IND_TYPE f162 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_2 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 31) (28272 / 912)
for (f161 = f162, f161_p_0 = 0;
	f161 < f162 + 28272;
	f161 += 912, f161_p_0 += 912){
		for (y120 = y121, y120_p_0 = 0;
			y120 < y121 + 8;
			y120 += 8, y120_p_0 += 8){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
			// T (x, 1) (17 / 17)
			for (x161 = x162, x161_p_0 = 0;
				x161 < x162 + 17;
				x161 += 17, x161_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
				// T (f, 19) (912 / 48)
				for (f160 = f161, f160_p_1 = f161_p_0, f160_p_0 = 0;
					f160 < f161 + 912;
					f160 += 48, f160_p_1 += 48, f160_p_0 += 48){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 48
					// T (c, 2) (1024 / 512)
					for (c120 = c121, c120_p_0 = 0;
						c120 < c121 + 1024;
						c120 += 512, c120_p_0 += 512){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 48
						// T (y, 1) (ph_y / ph_y)
						for (y = y120, yp_1 = y120_p_0, yp_0 = 0;
							y < y120 + 8;
							y += 8, yp_1 += 8, yp_0 += 8){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 48
							// T (x, 17) (17 / 1)
							for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
								x160 < x161 + 17;
								x160 += 1, x160_p_1 += 1, x160_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 48
								// T (f, 3) (48 / 16)
								for (f = f160, fp_2 = f160_p_1, fp_1 = f160_p_0, fp_0 = 0;
									f < f160 + 48;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 16
									// T (x, 1) (1 / 1)
									for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
										x < x160 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 16
												// T (c, 512) (512 / 1)
												for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
													c < c120 + 512;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_680);
													mem_vec_680 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_681);
													mem_vec_681 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_682);
													mem_vec_682 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_683);
													mem_vec_683 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_684);
													mem_vec_684 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_685);
													mem_vec_685 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_686);
													mem_vec_686 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_687);
													mem_vec_687 = vec_15;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_681);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_683);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_687);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y120 = y121 + 8, y120_p_0 = 0;
			y120 < y121 + 8 + 9;
			y120 += 9, y120_p_0 += 9){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
			// T (x, 1) (17 / 17)
			for (x161 = x162, x161_p_0 = 0;
				x161 < x162 + 17;
				x161 += 17, x161_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 912
				// T (f, 19) (912 / 48)
				for (f160 = f161, f160_p_1 = f161_p_0, f160_p_0 = 0;
					f160 < f161 + 912;
					f160 += 48, f160_p_1 += 48, f160_p_0 += 48){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 48
					// T (c, 2) (1024 / 512)
					for (c120 = c121, c120_p_0 = 0;
						c120 < c121 + 1024;
						c120 += 512, c120_p_0 += 512){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 48
						// T (y, 1) (ph_y / ph_y)
						for (y = y120, yp_1 = y120_p_0, yp_0 = 0;
							y < y120 + 9;
							y += 9, yp_1 += 9, yp_0 += 9){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 48
							// T (x, 17) (17 / 1)
							for (x160 = x161, x160_p_1 = x161_p_0, x160_p_0 = 0;
								x160 < x161 + 17;
								x160 += 1, x160_p_1 += 1, x160_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 48
								// T (f, 3) (48 / 16)
								for (f = f160, fp_2 = f160_p_1, fp_1 = f160_p_0, fp_0 = 0;
									f < f160 + 48;
									f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 16
									// T (x, 1) (1 / 1)
									for (x = x160, xp_2 = x160_p_1, xp_1 = x160_p_0, xp_0 = 0;
										x < x160 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 16
												// T (c, 512) (512 / 1)
												for (c = c120, cp_1 = c120_p_0, cp_0 = 0;
													c < c120 + 512;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_688);
													mem_vec_688 = vec_0;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_4 = _mm512_set1_ps(scal_1);


													vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_689);
													mem_vec_689 = vec_3;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_6 = _mm512_set1_ps(scal_2);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_690);
													mem_vec_690 = vec_5;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_8 = _mm512_set1_ps(scal_3);


													vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_691);
													mem_vec_691 = vec_7;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_10 = _mm512_set1_ps(scal_4);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_692);
													mem_vec_692 = vec_9;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_12 = _mm512_set1_ps(scal_5);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_693);
													mem_vec_693 = vec_11;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_14 = _mm512_set1_ps(scal_6);


													vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_694);
													mem_vec_694 = vec_13;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_16 = _mm512_set1_ps(scal_7);


													vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_695);
													mem_vec_695 = vec_15;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_18 = _mm512_set1_ps(scal_8);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_696);
													mem_vec_696 = vec_17;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_695);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_696);
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