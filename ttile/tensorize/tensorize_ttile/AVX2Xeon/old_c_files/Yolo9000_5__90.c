#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (8, y); T (2, f); T (68, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c93_p_0, cp_1, c93, f, fp_0, x, xp_0, x155_p_0, x156_p_0, x157_p_0, xp_1, x155_p_1, x156_p_1, xp_2, x155_p_2, xp_3, x155, x156, x157, y, yp_0, y124_p_0, y125_p_0, yp_1, y124_p_1, yp_2, y124, y125;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y126 = 0;
IND_TYPE x158 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c94 = 0;
IND_TYPE f62 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y125 = y126, y125_p_0 = 0;
		y125 < y126 + 96;
		y125 += 32, y125_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x157 = x158, x157_p_0 = 0;
			x157 < x158 + 136;
			x157 += 136, x157_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y124 = y125, y124_p_1 = y125_p_0, y124_p_0 = 0;
				y124 < y125 + 32;
				y124 += 32, y124_p_1 += 32, y124_p_0 += 32){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x156 = x157, x156_p_1 = x157_p_0, x156_p_0 = 0;
					x156 < x157 + 136;
					x156 += 2, x156_p_1 += 2, x156_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f62, fp_0 = 0;
						f < f62 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y124, yp_2 = y124_p_1, yp_1 = y124_p_0, yp_0 = 0;
							y < y124 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x155 = x156, x155_p_2 = x156_p_1, x155_p_1 = x156_p_0, x155_p_0 = 0;
								x155 < x156 + 2;
								x155 += 2, x155_p_2 += 2, x155_p_1 += 2, x155_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c93 = c94, c93_p_0 = 0;
									c93 < c94 + 128;
									c93 += 32, c93_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x155, xp_3 = x155_p_2, xp_2 = x155_p_1, xp_1 = x155_p_0, xp_0 = 0;
										x < x155 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_716 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_717 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_718 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_719 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_720 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_721 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c93, cp_1 = c93_p_0, cp_0 = 0;
													c < c93 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_716);
													mem_vec_716 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_717);
													mem_vec_717 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_718);
													mem_vec_718 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_719);
													mem_vec_719 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_720);
													mem_vec_720 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_721);
													mem_vec_721 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_722);
													mem_vec_722 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_723);
													mem_vec_723 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_724);
													mem_vec_724 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_725);
													mem_vec_725 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_726);
													mem_vec_726 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_727);
													mem_vec_727 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_728);
													mem_vec_728 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_729);
													mem_vec_729 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_730);
													mem_vec_730 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_731);
													mem_vec_731 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_716);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_717);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_718);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_719);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_720);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_721);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_722);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_723);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_724);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_725);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_726);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_727);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_728);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_729);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_730);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_731);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y125 = y126 + 96, y125_p_0 = 0;
		y125 < y126 + 96 + 40;
		y125 += 40, y125_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 1) (136 / 136)
		for (x157 = x158, x157_p_0 = 0;
			x157 < x158 + 136;
			x157 += 136, x157_p_0 += 136){
			// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y124 = y125, y124_p_1 = y125_p_0, y124_p_0 = 0;
				y124 < y125 + 40;
				y124 += 40, y124_p_1 += 40, y124_p_0 += 40){
				// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
				// T (x, 68) (136 / 2)
				for (x156 = x157, x156_p_1 = x157_p_0, x156_p_0 = 0;
					x156 < x157 + 136;
					x156 += 2, x156_p_1 += 2, x156_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f62, fp_0 = 0;
						f < f62 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y124, yp_2 = y124_p_1, yp_1 = y124_p_0, yp_0 = 0;
							y < y124 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x155 = x156, x155_p_2 = x156_p_1, x155_p_1 = x156_p_0, x155_p_0 = 0;
								x155 < x156 + 2;
								x155 += 2, x155_p_2 += 2, x155_p_1 += 2, x155_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c93 = c94, c93_p_0 = 0;
									c93 < c94 + 128;
									c93 += 32, c93_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x155, xp_3 = x155_p_2, xp_2 = x155_p_1, xp_1 = x155_p_0, xp_0 = 0;
										x < x155 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_732 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_733 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_734 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_735 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_736 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_737 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c93, cp_1 = c93_p_0, cp_0 = 0;
													c < c93 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_732);
													mem_vec_732 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_733);
													mem_vec_733 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_734);
													mem_vec_734 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_735);
													mem_vec_735 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_736);
													mem_vec_736 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_737);
													mem_vec_737 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_738);
													mem_vec_738 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_739);
													mem_vec_739 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_740);
													mem_vec_740 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_741);
													mem_vec_741 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_742);
													mem_vec_742 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_743);
													mem_vec_743 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_744);
													mem_vec_744 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_745);
													mem_vec_745 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_746);
													mem_vec_746 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_747);
													mem_vec_747 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_748);
													mem_vec_748 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_749);
													mem_vec_749 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_750);
													mem_vec_750 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_751);
													mem_vec_751 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_732);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_733);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_734);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_735);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_736);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_737);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_738);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_739);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_740);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_741);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_742);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_743);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_747);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_751);
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